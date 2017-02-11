//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/is_option.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/state_from_args.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::variant::variadic<
	fcppt::string,
	fcppt::options::state::name_pair
>
variant;

variant
get_type(
	fcppt::string const &_value
)
{
	return
		fcppt::options::is_option(
			_value
		)
		?
			variant{
				fcppt::optional::copy_value(
					fcppt::container::at_optional(
						_value,
						1u
					)
				)
				==
				fcppt::optional::make(
					FCPPT_TEXT('-')
				)
				?
					std::make_pair(
						_value.substr(
							2u
						),
						fcppt::options::state::is_short{
							false
						}
					)
				:
					std::make_pair(
						_value.substr(
							1u
						),
						fcppt::options::state::is_short{
							true
						}
					)
			}
		:
			variant{
				_value
			}
		;
}

}

fcppt::options::state
fcppt::options::detail::state_from_args(
	fcppt::args_vector const &_args,
	fcppt::options::has_parameter_set const &_parameters
)
{
	fcppt::args_vector args;

	fcppt::options::state::flag_map flags;

	fcppt::options::state::options_map options;

	// TODO: Find a better way than iterators
	for(
		fcppt::args_vector::const_iterator it{
			_args.begin()
		},
		end = _args.end();
		it != end;
		++it
	)
	{
		fcppt::string const &cur{
			*it
		};

		fcppt::variant::match(
			get_type(
				cur
			),
			[
				&args
			](
				fcppt::string const &_arg
			)
			{
				args.push_back(
					_arg
				);
			},
			[
				&_parameters,
				&it,
				end,
				&flags,
				&options
			](
				fcppt::options::state::name_pair const &_name
			){
				if(
					_parameters.count(
						_name.first
					)
					==
					0u
				)
					++flags[
						_name
					];
				else
					fcppt::optional::maybe(
						fcppt::optional::make_if(
							std::next(
								it
							)
							!=
							end,
							[
								it
							]{
								return
									fcppt::make_cref(
										*std::next(
											it
										)
									);
							}
						),
						[
							&_name,
							&options
						]{
							options[
								_name
							].push_back(
								fcppt::string{}
							);
						},
						[
							&_name,
							&it,
							&options
						](
							fcppt::reference<
								fcppt::string const
							> const _value
						)
						{
							options[
								_name
							].push_back(
								_value.get()
							);

							++it;
						}
					);
			}
		);
	}

	return
		fcppt::options::state{
			std::move(
				args
			),
			std::move(
				flags
			),
			std::move(
				options
			)
		};
}

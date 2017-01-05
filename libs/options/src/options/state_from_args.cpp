//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_from_args.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::options::state
fcppt::options::state_from_args(
	fcppt::args_vector const &_args,
	fcppt::options::has_parameter_set const &_parameters
)
{
	fcppt::args_vector args;

	fcppt::options::state::flag_map flags;

	fcppt::options::state::options_map options;

	// TODO: Separate this code
	for(
		fcppt::args_vector::const_iterator it{
			_args.begin()
		},
		end = _args.end();
		it != end;
		++it
	)
	{
		std::string const &cur{
			*it
		};

		fcppt::optional::maybe(
			fcppt::optional::make_if(
				fcppt::optional::copy_value(
					fcppt::container::maybe_front(
						cur
					)
				)
				==
				fcppt::optional::make(
					'-'
				),
				[
					&cur
				]{
					return
						fcppt::optional::copy_value(
							fcppt::container::at_optional(
								cur,
								1u
							)
						)
						==
						fcppt::optional::make(
							'-'
						)
						?
							cur.substr(
								2u
							)
						:
							cur.substr(
								1u
							)
						;
				}
			),
			[
				&cur,
				&args
			]{
				args.push_back(
					cur
				);
			},
			[
				&_parameters,
				&it,
				end,
				&flags,
				&options
			](
				std::string const &_name
			){
				if(
					!_parameters.count(
						_name
					)
				)
					++flags[
						_name
					];
				else
					// TODO: What do we do in this case?
					fcppt::optional::maybe_void(
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
							&it,
							&options
						](
							fcppt::reference<
								std::string const
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

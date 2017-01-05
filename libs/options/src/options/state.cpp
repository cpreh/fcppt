//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::state::state(
	fcppt::args_vector &&_args,
	flag_map &&_flags,
	options_map &&_options
)
:
	args_(
		fcppt::algorithm::reverse(
			std::move(
				_args
			)
		)
	),
	flags_(
		std::move(
			_flags
		)
	),
	options_(
		fcppt::algorithm::map<
			options_map
		>(
			fcppt::container::make_move_range(
				std::move(
					_options
				)
			),
			[](
				options_map::value_type &&_value
			)
			{
				return
					options_map::value_type{
						std::move(
							_value.first
						),
						fcppt::algorithm::reverse(
							std::move(
								_value.second
							)
						)
					};
			}
		)
	)
{
}

fcppt::optional_std_string
fcppt::options::state::pop_arg()
{
	return
		fcppt::container::pop_back(
			args_
		);
}

bool
fcppt::options::state::pop_flag(
	std::string const &_name
)
{
	return
		fcppt::optional::from(
			fcppt::optional::map(
				fcppt::container::find_opt_mapped(
					flags_,
					_name
				),
				[](
					fcppt::reference<
						flag_count
					> const _count
				)
				{
					if(
						_count.get()
						==
						0u
					)
						return
							false;
					--_count.get();

					return
						true;
				}
			),
			fcppt::const_(
				false
			)
		);
}

fcppt::optional_std_string
fcppt::options::state::pop_option(
	std::string const &_name
)
{
	return
		fcppt::optional::bind(
			fcppt::container::find_opt_mapped(
				options_,
				_name
			),
			[](
				fcppt::reference<
					fcppt::args_vector
				> const _args
			)
			{
				return
					fcppt::container::pop_back(
						_args.get()
					);
			}
		);
}

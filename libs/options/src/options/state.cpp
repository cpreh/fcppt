//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
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

fcppt::optional_string
fcppt::options::state::pop_arg()
{
	return
		fcppt::container::pop_back(
			args_
		);
}

bool
fcppt::options::state::pop_flag(
	fcppt::string const &_name,
	is_short const _is_short
)
{
	return
		fcppt::optional::from(
			fcppt::optional::map(
				fcppt::container::find_opt_iterator(
					flags_,
					std::make_pair(
						_name,
						_is_short
					)
				),
				[
					this
				](
					flag_map::iterator const _it
				)
				{
					// TODO: This is ugly
					flag_count &count{
						_it->second
					};

					bool const has_flag{
						count
						>
						0u
					};

					if(
						has_flag
					)
						--count;

					if(
						count
						==
						0u
					)
						flags_.erase(
							_it
						);

					return
						has_flag;
				}
			),
			fcppt::const_(
				false
			)
		);
}

fcppt::optional_string
fcppt::options::state::pop_option(
	fcppt::string const &_name,
	is_short const _is_short
)
{
	return
		fcppt::optional::bind(
			fcppt::container::find_opt_iterator(
				options_,
				std::make_pair(
					_name,
					_is_short
				)
			),
			[
				this
			](
				options_map::iterator const _it
			)
			{
				// TODO: This is ugly
				auto result{
					fcppt::container::pop_back(
						_it->second
					)
				};

				if(
					_it->second.empty()
				)
					options_.erase(
						_it
					);

				return
					result;
			}
		);
}

fcppt::args_vector const &
fcppt::options::state::leftover_args() const
{
	return
		args_;
}

fcppt::options::state::flag_map const &
fcppt::options::state::leftover_flags() const
{
	return
		flags_;
}

fcppt::options::state::options_map const &
fcppt::options::state::leftover_options() const
{
	return
		options_;
}

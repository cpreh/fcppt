//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/join.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Map,
	typename GetResult,
	typename CheckRemove
>
fcppt::optional::object<
	typename
	std::result_of<
		GetResult(
			fcppt::reference<
				typename
				Map::mapped_type
			>
		)
	>::type
>
get_element(
	Map &_map,
	typename Map::key_type const &_key,
	GetResult const &_get_result,
	CheckRemove const &_check_remove
)
{
	return
		fcppt::optional::map(
			fcppt::container::find_opt_iterator(
				_map,
				_key
			),
			[
				&_map,
				&_get_result,
				&_check_remove
			](
				typename Map::iterator const _it
			)
			{
				auto result(
					_get_result(
						fcppt::make_ref(
							_it->second
						)
					)
				);

				if(
					_check_remove(
						_it->second
					)
				)
					_map.erase(
						_it
					);

				return
					result;
			}
		);
}

}


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
			get_element(
				flags_,
				std::make_pair(
					_name,
					_is_short
				),
				[](
					fcppt::reference<
						flag_count
					> const _count
				)
				{
					bool const has_count{
						_count.get()
						>
						0u
					};

					if(
						has_count
					)
						--_count.get();

					return
						has_count;
				},
				[](
					flag_count const _count
				)
				{
					return
						_count
						==
						0u;
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
		fcppt::optional::join(
			get_element(
				options_,
				std::make_pair(
					_name,
					_is_short
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
				},
				[](
					fcppt::args_vector const &_args
				)
				{
					return
						_args.empty();
				}
			)
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

bool
fcppt::options::state::empty() const
{
	return
		this->leftover_args().empty()
		&&
		this->leftover_flags().empty()
		&&
		this->leftover_options().empty();
}

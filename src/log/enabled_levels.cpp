//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/enum_array_fold.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/level.hpp>


fcppt::log::enabled_level_array const
fcppt::log::enabled_levels(
	fcppt::log::level const _level
)
{
	return
		fcppt::algorithm::enum_array_fold<
			fcppt::log::enabled_level_array
		>(
			[
				_level
			](
				fcppt::log::level const _index
			)
			{
				return
					_level
					<=
					_index;
			}
		);
}

//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/level.hpp>


fcppt::log::enabled_level_array const
fcppt::log::enabled_levels(
	fcppt::log::level const _level
)
{
	fcppt::log::enabled_level_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		index,
		fcppt::log::level
	)
		ret[
			static_cast<
				fcppt::log::enabled_level_array::size_type
			>(
				index
			)
		] =
			_level <= index;

	return ret;
}

//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/foreach_enumerator_start.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/src/log/set_levels.hpp>


void
fcppt::log::set_levels(
	fcppt::log::object &_object,
	fcppt::log::level const _level,
	void(
		fcppt::log::object::*_fun
	)(
		fcppt::log::level
	)
)
{
	FCPPT_FOREACH_ENUMERATOR_START(
		index,
		fcppt::log::level,
		_level
	)
		(_object.*_fun)(
			index
		);
}

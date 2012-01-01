//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "set_levels.hpp"
#include <fcppt/foreach_enumerator_start.hpp>
#include <fcppt/log/object.hpp>


void
fcppt::log::set_levels(
	object &_object,
	level::type const _level,
	void (object::*_fun)(level::type)
)
{
	FCPPT_FOREACH_ENUMERATOR_START(
		index,
		log::level,
		_level
	)
		(_object.*_fun)(
			index
		);
}

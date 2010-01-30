//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "set_levels.hpp"
#include <fcppt/log/object.hpp>
#include <fcppt/foreach_enumerator_start.hpp>

void
fcppt::log::set_levels(
	object &object_,
	level::type const level_,
	void (object::*fun)(level::type)
)
{
	FCPPT_FOREACH_ENUMERATOR_START(
		i,
		level,
		level_
	)
		(object_.*fun)(
			i
		);
}

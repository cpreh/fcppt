//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/activate_levels.hpp>
#include <fcppt/log/object.hpp>
#include "set_levels.hpp"

void
fcppt::log::activate_levels(
	object &object_,
	level::type const level_
)
{
	set_levels(
		object_,
		level_,
		&object::activate
	);
}

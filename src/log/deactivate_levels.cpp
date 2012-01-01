//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/deactivate_levels.hpp>
#include <fcppt/log/object.hpp>
#include "set_levels.hpp"

void
fcppt::log::deactivate_levels(
	log::object &_object,
	level::type const _level
)
{
	log::set_levels(
		_object,
		_level,
		&object::deactivate
	);
}

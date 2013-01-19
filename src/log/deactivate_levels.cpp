//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/deactivate_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/src/log/set_levels.hpp>


void
fcppt::log::deactivate_levels(
	fcppt::log::object &_object,
	fcppt::log::level const _level
)
{
	fcppt::log::set_levels(
		_object,
		_level,
		&fcppt::log::object::deactivate
	);
}

//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_SET_LEVELS_HPP_INCLUDED
#define FCPPT_SRC_LOG_SET_LEVELS_HPP_INCLUDED

#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

void
set_levels(
	fcppt::log::object &,
	fcppt::log::level,
	void(
		fcppt::log::object::*
	)(
		fcppt::log::level
	)
);

}
}

#endif

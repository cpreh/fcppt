//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ACTIVATE_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_ACTIVATE_LEVELS_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Activates all the log levels that are equal or higher.

\ingroup fcpptlog

Activates all log levels for \a logger starting at and including \a level.

For example, specifying log::level::warning will activate log::level::error and
log::level::fatal as well.

\param logger The logger to activate the levels for
\param level The lower bound of the levels to activate
*/
FCPPT_SYMBOL
void
activate_levels(
	fcppt::log::object &logger,
	fcppt::log::level level
);

}
}

#endif

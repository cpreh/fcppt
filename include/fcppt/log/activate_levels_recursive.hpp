//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ACTIVATE_LEVELS_RECURSIVE_HPP_INCLUDED
#define FCPPT_LOG_ACTIVATE_LEVELS_RECURSIVE_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Activates all the log levels that are equal or higher in all loggers.

\ingroup fcpptlog

Activates all log levels starting at and including \a level for all loggers
that are reachable from \a location,

\param context The logger context
\param location The location of the start logger
\param level The lower bound of the levels to activate
*/
FCPPT_SYMBOL
void
activate_levels_recursive(
	fcppt::log::context &context,
	fcppt::log::location const &location,
	fcppt::log::level level
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEACTIVATE_LEVELS_RECURSIVE_HPP_INCLUDED
#define FCPPT_LOG_DEACTIVATE_LEVELS_RECURSIVE_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Deactivates all the log levels that are equal or higher in all loggers.

\ingroup fcpptlog

Deactivates all log levels starting at and including \a level for all loggers
that are reachable from \a location,

\param context The logger context
\param location The location of the start logger
\param level The lower bound of the levels to deactivate
*/
FCPPT_LOG_DETAIL_SYMBOL
void
deactivate_levels_recursive(
	fcppt::log::context &context,
	fcppt::log::location const &location,
	fcppt::log::level level
);

}
}

#endif

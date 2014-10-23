//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEACTIVATE_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_DEACTIVATE_LEVELS_HPP_INCLUDED

#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Deactivates all the log levels that are equal or higher.

\ingroup fcpptlog

Deactivates all log levels for \a logger starting at and including \a level.

For example, specifying log::level::warning will deactivate log::level::error
and log::level::fatal as well.

\param logger The logger to deactivate the levels for
\param level The lower bound of the levels to deactivate
*/
FCPPT_LOG_DETAIL_SYMBOL
void
deactivate_levels(
	fcppt::log::object &logger,
	fcppt::log::level level
);

}
}

#endif

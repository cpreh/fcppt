//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEACTIVATE_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_DEACTIVATE_LEVELS_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/// Deactivates all the log levels that are equal or higher.
/** @see activate_levels
*/
FCPPT_SYMBOL void
deactivate_levels(
	object &,
	level::type
);

}
}

#endif

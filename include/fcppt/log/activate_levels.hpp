//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ACTIVATE_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_ACTIVATE_LEVELS_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// Activates all the log levels that are equal or higher.
/**
 * For example specifying log::level::warning will activate log::level::error and log::level::fatal as well.
*/
FCPPT_SYMBOL void
activate_levels(
	object &,
	level::type
);

}
}

#endif

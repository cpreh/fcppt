//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ENABLED_LEVELS_HPP_INCLUDED
#define FCPPT_LOG_ENABLED_LEVELS_HPP_INCLUDED

#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// Creates an enabled_level_array which has every entry set to true that is greater or equal to the parameter
FCPPT_SYMBOL enabled_level_array const
enabled_levels(
	level::type
);

}
}

#endif

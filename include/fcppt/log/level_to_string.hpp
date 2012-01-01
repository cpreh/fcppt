//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/level.hpp>


namespace fcppt
{
namespace log
{

/// Convert a log level to its string representation
FCPPT_SYMBOL string const
level_to_string(
	level::type
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/level_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Converts a log level to its string representation

\ingroup fcpptlog

Converts a log level given by \a level to its enumerator name as a string.

\return The log level as a string

\warning The behaviour is undefined if fcppt::log::level::size is passed.
*/
FCPPT_SYMBOL
fcppt::string
level_to_string(
	fcppt::log::level level
);

}
}

#endif

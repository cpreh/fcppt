//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/level.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Converts the name of a log level to its enum

\ingroup fcpptlog

Converts the name of a log level given by \a name to its corresponding level
enumerator. Accepts all strings as parameters that are listed in
fcppt::log::level::type

\param name the name of the log level

\throw fcppt::log::exception if \a name is invalid
*/
FCPPT_SYMBOL
fcppt::log::level
level_from_string(
	fcppt::string const &name
);

}
}

#endif


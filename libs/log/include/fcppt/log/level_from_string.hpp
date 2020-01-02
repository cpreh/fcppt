//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Converts the name of a log level to its enum

\ingroup fcpptlog

Converts the name of a log level given by \a name to its corresponding level
enumerator. Accepts all strings as parameters that are listed in #fcppt::log::level.

\param name the name of the log level
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::optional_level
level_from_string(
	fcppt::string const &name
);

}
}

#endif


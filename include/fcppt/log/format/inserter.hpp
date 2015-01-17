//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_INSERTER_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Inserts a text given a format string

\ingroup fcpptlog

Inserts \a text into \a format_string using \link fcppt::format \endlink.

\param format_string The format string to use

\param text The text to insert

\return The result of the insertion
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::string
inserter(
	fcppt::string const &format_string,
	fcppt::string const &text
);

}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_TIME_STAMP_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_TIME_STAMP_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Puts a time stamp in front of a string

\ingroup fcpptlog

Puts a time stamp in front of \a text as if it was obtained by \link
fcppt::time::std_time \endlink and formatted by \link fcppt::time::output_tm
\endlink.

\param text The string to put the time stamp in front of

\return The formatted string
*/
FCPPT_SYMBOL
fcppt::string const
time_stamp(
	fcppt::string const &text
);

}
}
}

#endif

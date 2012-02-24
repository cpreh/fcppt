//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_TIME_STAMP_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_TIME_STAMP_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Creates a formatter that prints a time stamp

Creates a formatter that prints a time stamp in front like \link
fcppt::log::format::time_stamp \endlink does.

\return A new formatter that prints a time stamp
*/
FCPPT_SYMBOL
fcppt::log::format::function const
create_time_stamp();

}
}
}

#endif

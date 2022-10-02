//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_FORMAT_TIME_STAMP_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_TIME_STAMP_HPP_INCLUDED

#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/function.hpp>

namespace fcppt::log::format
{
/**
\brief Creates a formatter that prints a time stamp.

\ingroup fcpptlog

Creates a formatter that prints a time stamp in front.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::format::function time_stamp();

}

#endif

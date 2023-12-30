//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_OUT_HPP_INCLUDED
#define FCPPT_LOG_OUT_HPP_INCLUDED

#include <fcppt/log/detail/output_helper.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output.hpp> // IWYU pragma: keep

namespace fcppt::log
{
/**
\brief Trampoline to create logger output

\ingroup fcpptlog

Use this object to output to a log stream.
*/
FCPPT_LOG_DETAIL_SYMBOL
extern fcppt::log::detail::output_helper const out;

}

#endif

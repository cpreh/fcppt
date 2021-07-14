//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TIME_LOCALTIME_HPP_INCLUDED
#define FCPPT_TIME_LOCALTIME_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

namespace fcppt::time
{
/**
\brief A wrapper around <code>%std::localtime</code>.

\ingroup fcppttime

Converts \a time to an <code>%std::tm</code> using
<code>%std::localtime</code>.

\throw <code>std::runtime_error</code> on failure.
*/
FCPPT_DETAIL_SYMBOL
std::tm localtime(std::time_t time);

}

#endif

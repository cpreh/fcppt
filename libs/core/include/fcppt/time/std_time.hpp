//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TIME_STD_TIME_HPP_INCLUDED
#define FCPPT_TIME_STD_TIME_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace time
{
/**
\brief A wrapper around <code>%std::time</code>

\ingroup fcppttime

A wrapper around <code>%std::time</code>, returning the current time.

\throw fcppt::time::exception if an error occurs
*/
FCPPT_DETAIL_SYMBOL
std::time_t std_time();

}
}

#endif

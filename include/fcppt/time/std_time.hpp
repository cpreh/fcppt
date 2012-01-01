//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_STD_TIME_HPP_INCLUDED
#define FCPPT_TIME_STD_TIME_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace time
{

/// Returns the seconds since the epoch (1.1.1970 00:00)
/**
 * Calls std::time(0)
 * @throws time::exception if an error occurs
*/
FCPPT_SYMBOL
std::time_t
std_time();

}
}

#endif

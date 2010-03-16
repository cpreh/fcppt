//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_SLEEP_HPP_INCLUDED
#define FCPPT_TIME_SLEEP_HPP_INCLUDED

#include <fcppt/time/sleep_duration.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace time
{

/// Sleep for at least a given time, unless interrupted
/**
 * @throws sleep_interrupted if the sleep didn't finish
*/
FCPPT_SYMBOL
void
sleep(
	sleep_duration const &
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_SLEEP_HPP_INCLUDED
#define FCPPT_THREAD_SLEEP_HPP_INCLUDED

#include <fcppt/thread/sleep_duration.hpp>
#include <fcppt/thread/symbol.hpp>


namespace fcppt
{
namespace thread
{

/// Let the current thread sleep
/**
 * This is different from 'time::sleep'.
 * It is important to let threads sleep with this function.
 * Equivalent to boost::thread::sleep
*/
FCPPT_THREAD_SYMBOL
void
sleep(
	fcppt::thread::sleep_duration const &
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2012.
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

/**
\brief Lets the current thread sleep

\ingroup fcpptthread

Lets the current thread sleep for \a duration. This is a different function
than fcppt::time::sleep and should be used inside threads that have been
started through fcppt::thread::object

\param duration The duration to sleep for
*/
FCPPT_THREAD_SYMBOL
void
sleep(
	fcppt::thread::sleep_duration const &duration
);

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_HARDWARE_CONCURRENCY_HPP_INCLUDED
#define FCPPT_THREAD_HARDWARE_CONCURRENCY_HPP_INCLUDED

#include <fcppt/thread/hardware_concurrency_type.hpp>
#include <fcppt/thread/symbol.hpp>


namespace fcppt
{
namespace thread
{

/**
\brief Returns the number of concurrent threads that can run

\ingroup fcpptthread

\return The number of possible concurrent threads or 0 if the information is
not available.
*/
FCPPT_THREAD_SYMBOL
fcppt::thread::hardware_concurrency_type
hardware_concurrency();

}
}

#endif

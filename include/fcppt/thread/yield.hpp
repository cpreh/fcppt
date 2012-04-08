//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_YIELD_HPP_INCLUDED
#define FCPPT_THREAD_YIELD_HPP_INCLUDED

#include <fcppt/thread/hardware_concurrency_type.hpp>
#include <fcppt/thread/symbol.hpp>


namespace fcppt
{
namespace thread
{

/**
\brief Give other threads a chance to get CPU time

\ingroup fcpptthread

Can be called from any thread and gives other threads a chance to run.
*/
FCPPT_THREAD_SYMBOL
void
yield();

}
}

#endif

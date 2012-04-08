//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_TASK_HPP_INCLUDED
#define FCPPT_THREAD_TASK_HPP_INCLUDED

#include <fcppt/function/object.hpp>


namespace fcppt
{
namespace thread
{

/**
\brief The type of function a thread runs

\ingroup fcpptthread
*/
typedef fcppt::function::object<
	void ()
> task;

}
}

#endif


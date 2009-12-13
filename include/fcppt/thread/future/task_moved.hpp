#ifndef FCPPT_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL task_moved
:
	public exception
{
public:
	FCPPT_SYMBOL task_moved();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED

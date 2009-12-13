#ifndef FCPPT_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL task_already_started
:
	public exception
{
public:
	FCPPT_SYMBOL task_already_started();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED

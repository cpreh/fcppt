#ifndef SGE_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED
#define SGE_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL task_already_started
:
	public exception
{
public:
	SGE_SYMBOL task_already_started();
};
}
}
}

#endif // SGE_THREAD_FUTURE_TASK_ALREADY_STARTED_HPP_INCLUDED

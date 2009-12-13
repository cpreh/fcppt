#ifndef SGE_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED
#define SGE_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL task_moved
:
	public exception
{
public:
	SGE_SYMBOL task_moved();
};
}
}
}

#endif // SGE_THREAD_FUTURE_TASK_MOVED_HPP_INCLUDED

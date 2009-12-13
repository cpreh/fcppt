#ifndef SGE_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED
#define SGE_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL broken_promise
:
	public exception
{
public:
	SGE_SYMBOL broken_promise();
};
}
}
}

#endif // SGE_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED

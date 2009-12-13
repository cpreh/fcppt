#ifndef FCPPT_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL broken_promise
:
	public exception
{
public:
	FCPPT_SYMBOL broken_promise();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_BROKEN_PROMISE_HPP_INCLUDED

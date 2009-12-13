#ifndef FCPPT_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL promise_already_satisfied
:
	public exception
{
public:
	FCPPT_SYMBOL promise_already_satisfied();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED

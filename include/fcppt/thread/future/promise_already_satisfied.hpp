#ifndef SGE_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED
#define SGE_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL promise_already_satisfied
:
	public exception
{
public:
	SGE_SYMBOL promise_already_satisfied();
};
}
}
}

#endif // SGE_THREAD_FUTURE_PROMISE_ALREADY_SATISFIED_HPP_INCLUDED

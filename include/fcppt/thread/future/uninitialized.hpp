#ifndef FCPPT_THREAD_FUTURE_UNINITIALIZED_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_UNINITIALIZED_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL uninitialized
:
	public exception
{
public:
	FCPPT_SYMBOL uninitialized();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_UNINITIALIZED_HPP_INCLUDED

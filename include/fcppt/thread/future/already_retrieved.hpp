#ifndef FCPPT_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED

#include <fcppt/exception.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
class FCPPT_CLASS_SYMBOL already_retrieved
:
	public exception
{
public:
	FCPPT_SYMBOL already_retrieved();
};
}
}
}

#endif // FCPPT_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED

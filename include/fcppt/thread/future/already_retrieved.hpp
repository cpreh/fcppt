#ifndef SGE_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED
#define SGE_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL already_retrieved
:
	public exception
{
public:
	SGE_SYMBOL already_retrieved();
};
}
}
}

#endif // SGE_THREAD_FUTURE_ALREADY_RETRIEVED_HPP_INCLUDED

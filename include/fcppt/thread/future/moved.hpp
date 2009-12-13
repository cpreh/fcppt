#ifndef SGE_THREAD_FUTURE_MOVED_HPP_INCLUDED
#define SGE_THREAD_FUTURE_MOVED_HPP_INCLUDED

#include <sge/exception.hpp>

namespace sge
{
namespace thread
{
namespace future
{
class SGE_CLASS_SYMBOL moved
:
	public exception
{
public:
	SGE_SYMBOL moved();
};
}
}
}

#endif // SGE_THREAD_FUTURE_MOVED_HPP_INCLUDED

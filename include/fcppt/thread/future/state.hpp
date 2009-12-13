#ifndef SGE_THREAD_FUTURE_STATE_HPP_INCLUDED
#define SGE_THREAD_FUTURE_STATE_HPP_INCLUDED

namespace sge
{
namespace thread
{
namespace future
{
namespace state
{
enum type
{
	uninitialized,
	waiting,
	ready,
	moved
};
}
}
}
}

#endif // SGE_THREAD_FUTURE_STATE_HPP_INCLUDED

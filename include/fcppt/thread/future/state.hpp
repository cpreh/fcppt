#ifndef FCPPT_THREAD_FUTURE_STATE_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_STATE_HPP_INCLUDED

namespace fcppt
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

#endif // FCPPT_THREAD_FUTURE_STATE_HPP_INCLUDED

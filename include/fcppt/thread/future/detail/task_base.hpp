#ifndef SGE_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED
#define SGE_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED

#include <sge/thread/future/detail/object.hpp>
#include <sge/thread/future/task_already_started.hpp>

namespace sge
{
namespace thread
{
namespace future
{
namespace detail
{
template<typename T>
class task_base
:
	public object<T>
{
public:
	bool started_;

	task_base();
	void run();
	virtual void do_run() = 0;
};
}
}
}
}

template<typename T>
sge::thread::future::detail::task_base<T>::task_base()
:
	started_(
		false)
{}

template<typename T>
void sge::thread::future::detail::task_base<T>::run()
{
	{
		boost::lock_guard<boost::mutex> lk(
			task_base<T>::object_base::mutex_);
		if (started_)
			throw task_already_started();
		started_ = true;
	}
	do_run();
}

#endif // SGE_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED

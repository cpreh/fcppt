#ifndef FCPPT_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED

#include <fcppt/thread/future/detail/object.hpp>
#include <fcppt/thread/future/task_already_started.hpp>

namespace fcppt
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
fcppt::thread::future::detail::task_base<T>::task_base()
:
	started_(
		false)
{}

template<typename T>
void fcppt::thread::future::detail::task_base<T>::run()
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

#endif // FCPPT_THREAD_FUTURE_DETAIL_TASK_BASE_HPP_INCLUDED

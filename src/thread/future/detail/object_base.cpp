#include <fcppt/thread/future/detail/object_base.hpp>

fcppt::thread::future::detail::object_base::object_base()
:
	exception_(),
	done_(
		false),
	mutex_(),
	waiters_()
{
}

void fcppt::thread::future::detail::object_base::mark_finished_internal()
{
	done_ = true;
	waiters_.notify_all();
}

void fcppt::thread::future::detail::object_base::wait_internal(
	boost::unique_lock<boost::mutex> &_lock)
{
	while (!done_)
		waiters_.wait(
			_lock);
}

void fcppt::thread::future::detail::object_base::wait()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	wait_internal(
		lock);
}

bool fcppt::thread::future::detail::object_base::timed_wait_until_internal(
	boost::unique_lock<boost::mutex> &_lock,
	boost::system_time const &_time)
{
	while (!done_)
	{
		bool const success =
			waiters_.timed_wait(
				_lock,
				_time);

		if (!success && !done_)
			return false;
	}
	return true;
}

bool fcppt::thread::future::detail::object_base::timed_wait_until(
	boost::system_time const&_time)
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	return
		timed_wait_until_internal(
			lock,
			_time);
}

void fcppt::thread::future::detail::object_base::mark_exceptional_finish_internal(
	boost::exception_ptr const &_exception)
{
	exception_ = _exception;
	mark_finished_internal();
}

void fcppt::thread::future::detail::object_base::mark_exceptional_finish()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	mark_exceptional_finish_internal(
		boost::current_exception());
}

fcppt::thread::future::detail::object_base::~object_base()
{
}

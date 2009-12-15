#ifndef FCPPT_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
namespace detail
{
class FCPPT_CLASS_SYMBOL object_base
{
	FCPPT_NONCOPYABLE(object_base)
public:
	FCPPT_SYMBOL object_base();
	FCPPT_SYMBOL virtual ~object_base();
	FCPPT_SYMBOL void mark_finished_internal();
	FCPPT_SYMBOL void wait_internal(
		boost::unique_lock<boost::mutex> &);
	FCPPT_SYMBOL void wait();
	FCPPT_SYMBOL bool timed_wait_until_internal(
		boost::unique_lock<boost::mutex>&,
		boost::system_time const&);
	FCPPT_SYMBOL bool timed_wait_until(
		boost::system_time const&);
	FCPPT_SYMBOL void mark_exceptional_finish_internal(
		boost::exception_ptr const &e);
	FCPPT_SYMBOL void mark_exceptional_finish();
	boost::exception_ptr exception_;
	bool done_;
	boost::mutex mutex_;
	boost::condition_variable waiters_;
};
}
}
}
}

#endif // FCPPT_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED

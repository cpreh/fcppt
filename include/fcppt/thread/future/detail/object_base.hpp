#ifndef SGE_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED
#define SGE_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED

#include <sge/noncopyable.hpp>
#include <sge/export.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>

namespace sge
{
namespace thread
{
namespace future
{
namespace detail
{
class SGE_CLASS_SYMBOL object_base
{
SGE_NONCOPYABLE(object_base)
public:
	SGE_SYMBOL object_base();
	SGE_SYMBOL virtual ~object_base();
	SGE_SYMBOL void mark_finished_internal();
	SGE_SYMBOL void wait_internal(
		boost::unique_lock<boost::mutex> &);
	SGE_SYMBOL void wait();
	SGE_SYMBOL bool timed_wait_until_internal(
		boost::unique_lock<boost::mutex>&,
		boost::system_time const&);
	SGE_SYMBOL bool timed_wait_until(
		boost::system_time const&);
	SGE_SYMBOL void mark_exceptional_finish_internal(
		boost::exception_ptr const &e);
	SGE_SYMBOL void mark_exceptional_finish();
	boost::exception_ptr exception_;
	bool done_;
	boost::mutex mutex_;
	boost::condition_variable waiters_;
};
}
}
}
}

#endif // SGE_THREAD_FUTURE_DETAIL_OBJECT_BASE_HPP_INCLUDED

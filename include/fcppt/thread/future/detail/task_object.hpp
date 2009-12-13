#ifndef SGE_THREAD_FUTURE_DETAIL_TASK_OBJECT_HPP_INCLUDED
#define SGE_THREAD_FUTURE_DETAIL_TASK_OBJECT_HPP_INCLUDED

#include <sge/thread/future/detail/task_base.hpp>

namespace sge
{
namespace thread
{
namespace future
{
namespace detail
{
template<
	typename R,
	typename F
>
class task_object
:
	public task_base<R>
{
public:
	F f_;

	task_object(F const& f_);
	task_object(
		boost::detail::thread_move_t<F>);
	void do_run();
};

#if 0
template<typename F>
class task_object<void,F>
:
	public task_base<void>
{
public:
	F f_;

	task_object(
		F const&);
	task_object(
		boost::detail::thread_move_t<F>);
	void do_run();
};
#endif
}
}
}
}

template
<
	typename T,
	typename F
>
sge::thread::future::detail::task_object<T,F>::task_object(
	F const& _f)
:
	f_(
		_f)
{}

template
<
	typename T,
	typename F
>
sge::thread::future::detail::task_object<T,F>::task_object(
	boost::detail::thread_move_t<F> _f)
:
	f_(
		_f)
{}

template
<
	typename T,
	typename F
>
void sge::thread::future::detail::task_object<T,F>::do_run()
{
	try
	{
		mark_finished_with_result(
			f_());
	}
	catch(...)
	{
		this->mark_exceptional_finish();
	}
}

#if 0
template
<
	typename F
>
sge::thread::future::detail::task_object<void,F>::task_object(
	F const& _f)
:
	f_(
		_f)
{}

template
<
	typename F
>
sge::thread::future::detail::task_object<void,F>::task_object(
	boost::detail::thread_move_t<F> _f)
:
	f_(
		_f)
{}

template
<
	typename F
>
void sge::thread::future::detail::task_object<void,F>::do_run()
{
	try
	{
		f_();
		this->mark_finished_with_result();
	}
	catch(...)
	{
		this->mark_exceptional_finish();
	}
}
#endif

#endif // SGE_THREAD_FUTURE_DETAIL_TASK_OBJECT_HPP_INCLUDED

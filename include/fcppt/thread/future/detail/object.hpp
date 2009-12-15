#ifndef FCPPT_THREAD_FUTURE_DETAIL_OBJECT_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_DETAIL_OBJECT_HPP_INCLUDED

#include <fcppt/thread/future/detail/object_base.hpp>
#include <fcppt/thread/future/detail/traits.hpp>
#include <fcppt/thread/future/state.hpp>
#include <boost/type_traits/add_reference.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
namespace detail
{
template<typename T>
class object
:
	public object_base
{
public:
	typedef typename traits<T>::storage storage;
	typedef typename traits<T>::source_reference source_reference;
	typedef typename traits<T>::move_source move_source;
	typedef typename boost::add_reference<T>::type reference;

	storage result_;

	object();
	void mark_finished_with_result_internal(
		source_reference);
	void mark_finished_with_result_internal(
		move_source);
	void mark_finished_with_result(
		source_reference);
	void mark_finished_with_result(
		move_source);
	T move();
	bool try_move(
		reference);
	bool timed_move_until(
		reference,
		boost::system_time const &);
	reference get();
	bool try_get(
		reference);
	bool timed_get_until(
		reference,
		boost::system_time const&);
	future::state::type state();
};

#if 0
template<>
class object<void>
:
	public object_base
{
public:
	bool result_;

	object();
	void mark_finished_with_result_internal();
	void mark_finished_with_result();
	void move();
	void get();
	future::state::type state();
};
#endif
}
}
}
}

#include <boost/thread/locks.hpp>
#include <boost/throw_exception.hpp>
#include <fcppt/thread/future/moved.hpp>

template<typename T>
fcppt::thread::future::detail::object<T>::object()
:
	result_(0)
{
}

template<typename T>
void fcppt::thread::future::detail::object<T>::mark_finished_with_result_internal(
	source_reference _result)
{
	traits<T>::init(
		result_,
		_result);
	mark_finished_internal();
}

template<typename T>
void fcppt::thread::future::detail::object<T>::mark_finished_with_result_internal(
	move_source _result)
{
	traits<T>::init(
		result_,
		_result);
	mark_finished_internal();
}

template<typename T>
void fcppt::thread::future::detail::object<T>::mark_finished_with_result(
	source_reference _result)
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	mark_finished_with_result_internal(
		_result);
}

template<typename T>
void fcppt::thread::future::detail::object<T>::mark_finished_with_result(
	move_source _result)
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	mark_finished_with_result_internal(
		_result);
}

template<typename T>
T fcppt::thread::future::detail::object<T>::move()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);

	wait_internal(
		lock);

	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();

	return
		traits<T>::move(
			result_);
}

template<typename T>
bool fcppt::thread::future::detail::object<T>::try_move(
	reference _dest)
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	if (!done_)
		return false;
	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();
	traits<T>::move(
		result_,
		_dest);
	return true;
}

template<typename T>
bool fcppt::thread::future::detail::object<T>::timed_move_until(
	reference _dest,
	boost::system_time const &_time)
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	if (!timed_wait_until_internal(lock,_time))
		return false;
	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();
	traits<T>::move(
		result_,
		_dest);
	return true;
}

template<typename T>
typename fcppt::thread::future::detail::object<T>::reference
fcppt::thread::future::detail::object<T>::get()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	wait_internal(
		lock);
	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();
	return *result_;
}

template<typename T>
bool fcppt::thread::future::detail::object<T>::try_get(
	reference _dest)
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	if(!done_)
			return false;
	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();
	_dest = *result_;
	return true;
}

template<typename T>
bool fcppt::thread::future::detail::object<T>::timed_get_until(
	reference _dest,
	boost::system_time const &_time)
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	if (!timed_wait_until_internal(lock,_time))
		return false;
	if (exception_)
		boost::rethrow_exception(
			exception_);
	if (!result_)
		throw moved();
	_dest = *result_;
	return true;
}

template<typename T>
fcppt::thread::future::state::type
fcppt::thread::future::detail::object<T>::state()
{
	boost::lock_guard<boost::mutex>
		guard(
			mutex_);
	if(!done_)
		return state::waiting;
	return
		!result_ && !exception_
		? state::moved
		: state::ready;
}

#if 0
fcppt::thread::future::detail::object<void>::object()
:
	result_(
		false)
{}

void fcppt::thread::future::detail::object<void>::mark_finished_with_result_internal()
{
	result_ = true;
	mark_finished_internal();
}

void fcppt::thread::future::detail::object<void>::mark_finished_with_result()
{
	boost::lock_guard<boost::mutex> lock(
		mutex_);
	mark_finished_with_result_internal();
}

void fcppt::thread::future::detail::object<void>::move()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	wait_internal(
		lock);
	if(exception_)
		boost::rethrow_exception(
			exception_);
	if(!result_)
		throw moved();
	result_ = false;
}

void fcppt::thread::future::detail::object<void>::get()
{
	boost::unique_lock<boost::mutex> lock(
		mutex_);
	wait_internal(
		lock);
	if(exception_)
		boost::rethrow_exception(
			exception_);
	if(!result_)
		throw moved();
}

fcppt::thread::future::state::type fcppt::thread::future::detail::object<void>::state()
{
	boost::lock_guard<boost::mutex> guard(
		mutex_);
	if(!done_)
		return state::waiting;
	return
		!result_ && !exception_
		? state::moved
		: state::ready;
}
#endif

#endif // FCPPT_THREAD_FUTURE_DETAIL_OBJECT_HPP_INCLUDED

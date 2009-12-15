#ifndef FCPPT_THREAD_FUTURE_DETAIL_BASE_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_DETAIL_BASE_HPP_INCLUDED

#include <fcppt/thread/future/detail/object.hpp>
#include <fcppt/thread/future/uninitialized.hpp>
#include <fcppt/thread/future/state.hpp>
#include <fcppt/shared_ptr.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/thread/detail/move.hpp>
#include <boost/thread/thread_time.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
namespace detail
{
template<typename T>
class base
{
protected:
	typedef shared_ptr< detail::object<T> > object_ptr;
	typedef typename
	boost::mpl::if_<
		boost::is_void<T>,
		void,
		typename boost::add_reference<T>::type
	>::type reference;

	object_ptr object_;

	base();
	base(
		object_ptr);

public:
	void swap(
		base &);
	reference get();
	bool
	try_get(
		reference);

	template<typename Duration>
	bool
	timed_get(
		reference,
		Duration const&);

	bool
	timed_get_until(
		reference,
		boost::system_time const&);
	future::state::type state() const;
	bool is_ready() const;
	bool has_exception() const;
	bool has_value() const;
	bool was_moved() const;
	void wait() const;
	template<typename Duration>
	bool timed_wait(
		Duration const&) const;
	bool timed_wait_until(
		boost::system_time const&) const;
};
}
}
}
}

template<typename T>
fcppt::thread::future::detail::base<T>::base()
:
	object_()
{}

template<typename T>
fcppt::thread::future::detail::base<T>::base(
	object_ptr _object)
:
	object_(
		_object)
{}

template<typename T>
void fcppt::thread::future::detail::base<T>::swap(
	base &_rhs)
{
	object_.swap(
		_rhs.object_);
}

template<typename T>
typename fcppt::thread::future::detail::base<T>::reference
fcppt::thread::future::detail::base<T>::get()
{
	if (!object_)
		throw uninitialized();
	return object_->get();
}

template<typename T>
bool
fcppt::thread::future::detail::base<T>::try_get(
	reference _dest)
{
	if (!object_)
		throw uninitialized();
	return
		object_->try_get(
			_dest);
}

template<typename T>
template<typename Duration>
bool
fcppt::thread::future::detail::base<T>::timed_get(
	reference _dest,
	Duration const &_time)
{
	return
		timed_get_until(
			_dest,
			boost::get_system_time()+_time);
}

template<typename T>
bool
fcppt::thread::future::detail::base<T>::timed_get_until(
	reference _dest,
	boost::system_time const &_time)
{
	if (!object_)
		throw uninitialized();
	return
		object_->timed_get_until(
			_dest,
			_time);
}

template<typename T>
fcppt::thread::future::state::type
fcppt::thread::future::detail::base<T>::state() const
{
	if (!object_)
		throw uninitialized();
	return object_->state();
}

template<typename T>
bool fcppt::thread::future::detail::base<T>::is_ready() const
{
	return state() == fcppt::thread::future::state::ready;
}

template<typename T>
bool fcppt::thread::future::detail::base<T>::has_exception() const
{
	if(!object_)
		return false;
	boost::lock_guard<boost::mutex> guard(
		object_->mutex_);
	return
		object_->done_ && object_->exception_;
}

template<typename T>
bool fcppt::thread::future::detail::base<T>::has_value() const
{
	if(!object_)
		return false;
	boost::lock_guard<boost::mutex> guard(
		object_->mutex_);
	return
		object_->done_ && object_->result_;
}

template<typename T>
bool fcppt::thread::future::detail::base<T>::was_moved() const
{
	return state() == fcppt::thread::future::state::moved;
}

template<typename T>
void fcppt::thread::future::detail::base<T>::wait() const
{
	if (!object_)
		throw uninitialized();
	object_->wait();
}

template<typename T>
template<typename Duration>
bool fcppt::thread::future::detail::base<T>::timed_wait(
	Duration const& _time) const
{
	return
		timed_wait_until(
			boost::get_system_time()+_time);
}

template<typename T>
bool fcppt::thread::future::detail::base<T>::timed_wait_until(
	boost::system_time const& _time) const
{
	if (object_)
		throw uninitialized();
	return
		object_->timed_wait_until(
			_time);
}

#endif // FCPPT_THREAD_FUTURE_DETAIL_BASE_HPP_INCLUDED

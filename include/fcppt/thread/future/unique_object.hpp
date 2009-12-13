#ifndef SGE_THREAD_FUTURE_UNIQUE_OBJECT_HPP_INCLUDED
#define SGE_THREAD_FUTURE_UNIQUE_OBJECT_HPP_INCLUDED

#include <sge/thread/future/shared_object_fwd.hpp>
#include <sge/thread/future/detail/base.hpp>

namespace sge
{
namespace thread
{
namespace future
{
template<typename T>
class unique_object
:
	public detail::base<T>
{
private:
	typedef typename detail::base<T> base;

	unique_object(
		unique_object &);
	unique_object &operator=(
		unique_object &);
public:
	typedef typename base::reference reference;

	unique_object();
	unique_object(
		typename base::object_ptr);
	unique_object(
		boost::detail::thread_move_t<unique_object>);
	unique_object &operator=(
		boost::detail::thread_move_t<unique_object>);
	operator boost::detail::thread_move_t<unique_object>();
	T move();
	bool try_move(
		reference);
	template<typename Duration>
	bool timed_move(
		reference,
		Duration const &);
	bool timed_move_until(
		reference,
		boost::system_time const &);
private:
	friend class shared_object<T>;
};
}
}
}

template<typename T>
sge::thread::future::unique_object<T>::unique_object()
:
	base()
{
}

template<typename T>
sge::thread::future::unique_object<T>::unique_object(
	typename base::object_ptr _object)
:
	base(
		_object)
{
}

template<typename T>
sge::thread::future::unique_object<T>::unique_object(
	boost::detail::thread_move_t<unique_object> _other)
:
	base(
		_other->object_)
{
	_other->object_.reset();
}

template<typename T>
sge::thread::future::unique_object<T> &sge::thread::future::unique_object<T>::operator=(
	boost::detail::thread_move_t<unique_object> _other)
{
	this->object_ = _other->object_;
	_other->object_.reset();
	return *this;
}

template<typename T>
sge::thread::future::unique_object<T>::operator boost::detail::thread_move_t< sge::thread::future::unique_object<T> >()
{
	return
		boost::detail::thread_move_t<unique_object>(
			*this);
}

template<typename T>
T sge::thread::future::unique_object<T>::move()
{
	if (!this->object_)
		throw uninitialized();
	return this->object_->move();
}

template<typename T>
bool sge::thread::future::unique_object<T>::try_move(
	reference _dest)
{
	if (!this->object_)
		throw uninitialized();
	return
		this->object_->try_move(
			_dest);
}

template<typename T>
template<typename Duration>
bool sge::thread::future::unique_object<T>::timed_move(
	reference _dest,
	Duration const &_time)
{
	return
		timed_move_until(
			_dest,
			boost::get_system_time()+_time);
}

template<typename T>
bool sge::thread::future::unique_object<T>::timed_move_until(
	reference _dest,
	boost::system_time const &_time)
{
	if (!this->object_)
		throw uninitialized();
	return
		this->object_->timed_move_until(
			_dest,
			_time);
}

#endif // SGE_THREAD_FUTURE_UNIQUE_OBJECT_HPP_INCLUDED

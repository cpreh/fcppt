#ifndef SGE_THREAD_FUTURE_SHARED_OBJECT_HPP_INCLUDED
#define SGE_THREAD_FUTURE_SHARED_OBJECT_HPP_INCLUDED

#include <sge/thread/future/detail/base.hpp>

namespace sge
{
namespace thread
{
namespace future
{
template<typename T>
class shared_object
:
	public detail::base<T>
{
private:
	typedef typename detail::base<T> base;

	shared_object(
		unique_object<T> &);
	shared_object &operator=(
		unique_object<T> &);
public:
	typedef typename base::reference reference;

	shared_object();
	shared_object(
		typename base::object_ptr);
	shared_object(
		shared_object const &);
	shared_object(
		boost::detail::thread_move_t<shared_object>);
	shared_object(
		boost::detail::thread_move_t<unique_object<T> >);
	shared_object &operator=(
		shared_object const &);
	shared_object &operator=(
		boost::detail::thread_move_t<shared_object>);
	shared_object &operator=(
		boost::detail::thread_move_t<unique_object<T> >);
	operator boost::detail::thread_move_t<shared_object>();
};
}
}
}

template<typename T>
sge::thread::future::shared_object<T>::shared_object()
:
	base()
{
}

template<typename T>
sge::thread::future::shared_object<T>::shared_object(
	shared_object const &_rhs)
:
	base(
		_rhs.object_)
{
}

template<typename T>
sge::thread::future::shared_object<T>::shared_object(
	typename base::object_ptr _object)
:
	base(
		_object)
{
}

template<typename T>
sge::thread::future::shared_object<T>::shared_object(
	boost::detail::thread_move_t<shared_object> _other)
:
	base(
		_other->object_)
{
	_other->object_.reset();
}

template<typename T>
sge::thread::future::shared_object<T>::shared_object(
	boost::detail::thread_move_t<unique_object<T> > _other)
:
	base(
		_other->object_)
{
	_other->object_.reset();
}

template<typename T>
sge::thread::future::shared_object<T> &sge::thread::future::shared_object<T>::operator=(
	shared_object const &_rhs)
{
	this->object_ = _rhs.object_;
	return *this;
}

template<typename T>
sge::thread::future::shared_object<T> &sge::thread::future::shared_object<T>::operator=(
	boost::detail::thread_move_t<shared_object> _other)
{
	this->object_ = _other->object_;
	_other->object_.reset();
	return *this;
}

template<typename T>
sge::thread::future::shared_object<T> &sge::thread::future::shared_object<T>::operator=(
	boost::detail::thread_move_t<unique_object<T> > _other)
{
	this->object_.swap(
		_other->object_);
	_other->object_.reset();
	return *this;
}

template<typename T>
sge::thread::future::shared_object<T>::operator boost::detail::thread_move_t< sge::thread::future::shared_object<T> >()
{
	return
		boost::detail::thread_move_t<shared_object>(
			*this);
}

#endif // SGE_THREAD_FUTURE_SHARED_OBJECT_HPP_INCLUDED

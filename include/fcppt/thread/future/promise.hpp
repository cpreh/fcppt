#ifndef SGE_THREAD_FUTURE_PROMISE_HPP_INCLUDED
#define SGE_THREAD_FUTURE_PROMISE_HPP_INCLUDED

#include <sge/thread/future/unique_object.hpp>
#include <sge/thread/future/detail/traits.hpp>
#include <boost/thread/thread_time.hpp>
#include <boost/thread/detail/move.hpp>
#include <boost/exception_ptr.hpp>

namespace sge
{
namespace thread
{
namespace future
{
template<typename T>
class promise
{
//SGE_NONCOPYABLE(promise)
private:
	promise(promise &);
	promise &operator=(promise &);
public:
	promise();
	promise(
		boost::detail::thread_move_t<promise>);
	~promise();
	promise &operator=(
		boost::detail::thread_move_t<promise>);
	void swap(
		promise&);
	//::sge::thread::future::detail::unique_object<T> get_future();
	void set_value(
		typename ::sge::thread::future::detail::traits<T>::source_reference);
	void set_value(
		typename ::sge::thread::future::detail::traits<T>::move_source);
	void set_exception(
		boost::exception_ptr);
private:
	typedef shared_ptr< ::sge::thread::future::detail::object<T> > object_ptr;

	object_ptr object_;
	bool future_obtained_;
};

#if 0
template<>
class promise<void>
{
//SGE_NONCOPYABLE(promise)
private:
	promise(promise &);
	promise &operator=(promise &);
public:
	promise();
	promise(
		boost::detail::thread_move_t<promise>);
	~promise():
	promise &operator=(
		boost::detail::thread_move_t<promise>);
	void swap(
		promise&);
	::sge::thread::future::unique_object<void> future();
	void set_value();
	void set_exception(
		boost::exception_ptr);
private:
	typedef shared_ptr< ::sge::thread::future::detail::object<void> > object_ptr;

	object_ptr object_;
	bool future_obtained_;
};
#endif
}
}
}

template<typename T>
sge::thread::future::promise<T>::promise()
:
	object_(
		new detail::object<T>()),
	future_obtained_(
		false)
{
}

template<typename T>
sge::thread::future::promise<T>::promise(
	boost::detail::thread_move_t<promise> rhs)
:
	object_(
		rhs->object_),
	future_obtained_(
		rhs->future_obtained_)
{
}

template<typename T>
sge::thread::future::promise<T>::~promise()
{
	if (!object_)
		return;

	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);

	if(object_->done_)
		return;

	try
	{
		throw broken_promise();
	}
	catch(...)
	{
		object_->mark_exceptional_finish_internal(
			boost::current_exception());
	}
}

template<typename T>
sge::thread::future::promise<T> &sge::thread::future::promise<T>::operator=(
	boost::detail::thread_move_t<promise> rhs)
{
	object_ = rhs->object_;
	future_obtained_ = rhs->future_obtained_;
	rhs->object_.reset();
	return *this;
}

template<typename T>
void sge::thread::future::promise<T>::swap(
	promise& _other)
{
	object_.swap(
		_other.object_);
	std::swap(
		future_obtained_,
		_other.future_obtained_);
}

template<typename T>
sge::thread::future::unique_future<T> sge::thread::future::promise<T>::future()
{
	if (!object_)
		throw moved();
	if (future_obtained_)
		throw already_retrieved();
	future_obtained_ = true;
	return
		unique_future<T>(
			object_);
}

template<typename T>
void sge::thread::future::promise<T>::set_value(
	typename detail::future_traits<R>::source_reference r)
{
	if(!object_)
		throw moved();
	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);
	if(object_->done_)
		throw promise_already_satisfied();
	object_->mark_finished_with_result_internal(
		r);
}

template<typename T>
void sge::thread::future::promise<T>::set_value(
	typename detail::future_traits<R>::move_source r)
{
	if (!object_)
		throw moved();
	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);
	if(object_->done_)
		throw promise_already_satisfied();
	object_->mark_finished_with_result_internal(
		r);
}

template<typename T>
void sge::thread::future::promise<T>::set_exception(
	boost::exception_ptr p)
{
	if(!object_)
		throw moved();
	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);
	if(object_->done_)
		throw promise_already_satisfied();
	object_->mark_exceptional_finish_internal(
		p);
}


#if 0
sge::thread::future::promise<void>::promise()
:
	object_(
		new detail::object<void>()),
	future_obtained_(
		false)
{
}

sge::thread::future::promise<void>::promise(
	boost::detail::thread_move_t<promise> rhs)
:
	object_(
		rhs->object_),
	future_obtained_(
		rhs->future_obtained_)
{
}

sge::thread::future::promise<void>::~promise()
{
	if (!object_)
		return;

	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);

	if(object_->done_)
		return;

	try
	{
		throw broken_promise();
	}
	catch(...)
	{
		object_->mark_exceptional_finish_internal(
			boost::current_exception());
	}
}

sge::thread::future::promise<void> &sge::thread::future::promise<void>::operator=(
	boost::detail::thread_move_t<promise> rhs)
{
	object_ = rhs->object_;
	future_obtained_ = rhs->future_obtained_;
	rhs->object_.reset();
	return *this;
}

void sge::thread::future::promise<void>::swap(
	promise& _other)
{
	object_.swap(
		_other.object_);
	std::swap(
		future_obtained_,
		_other.future_obtained_);
}

sge::thread::future::unique_future<void> sge::thread::future::promise<void>::get_future()
{
	if(!object_)
		throw moved();
	if(future_obtained_)
		throw future_already_retrieved();
	future_obtained_ = true;
	return
		unique_future<void>(
			object_);
}

void sge::thread::future::promise<void>::set_value()
{
	if(!object_)
		throw moved();
	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);
	if(object_->done_)
		throw promise_already_satisfied();
	object_->mark_finished_with_result_internal();
}

void sge::thread::future::promise<void>::set_exception(
	boost::exception_ptr p)
{
	if(!object_)
		throw moved();
	boost::lock_guard<boost::mutex> lock(
		object_->mutex_);
	if (object_->done_)
		throw promise_already_satisfied();
	object_->mark_exceptional_finish_internal(
		p);
}
#endif

#endif // SGE_THREAD_FUTURE_PROMISE_HPP_INCLUDED

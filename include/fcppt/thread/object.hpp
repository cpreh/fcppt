//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_OBJECT_HPP_INCLUDED
#define FCPPT_THREAD_OBJECT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/thread/id.hpp>
#include <fcppt/thread/join_duration.hpp>
#include <fcppt/thread/native_handle.hpp>
#include <fcppt/thread/symbol.hpp>
#include <fcppt/thread/task.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/thread/thread.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace thread
{

/**
\brief A wrapper around <code>%boost::thread</code>

\ingroup fcpptthread

This wrapper around <code>%boost::thread</code> calls
<code>%std::terminate</code> in its destructor if the thread is neither joined
nor detached.
*/
class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	/**
	\brief Construct the thread and let it immediately run the task

	Constructs the thread, which will immediately run \a task

	\param task The task to run in the thread
	*/
	FCPPT_THREAD_SYMBOL
	object(
		fcppt::thread::task const &task
	);

	/**
	\brief Swaps the thread with another thread

	Swaps the thread with \a other

	\param other The thread to swap with
	*/
	FCPPT_THREAD_SYMBOL
	void
	swap(
		fcppt::thread::object &other
	);

	/**
	\brief Returns the id of this thread
	*/
	FCPPT_THREAD_SYMBOL
	fcppt::thread::id
	id() const;

	/**
	\brief Tells if the thread can be joined

	A thread is joinable if it has neither been joined nor detached yet.
	It is desired to join every thread eventually.
	*/
	FCPPT_THREAD_SYMBOL
	bool
	joinable() const;

	/**
	\brief Joins the thread

	If <code>this->joinable()</code> is true, this function will block
	until the thread has stopped running. Otherwise, the behaviour is
	unspecified.
	*/
	FCPPT_THREAD_SYMBOL
	void
	join();

	/**
	\brief Tries to join the thread

	Tries to join the thread, waiting for it to stop running for the period
	of \a duration.

	\param duration The duration to wait for the thread to stop running

	\return true if the thread was successfully joined, false otherwise
	*/
	FCPPT_THREAD_SYMBOL
	bool
	try_join(
		fcppt::thread::join_duration const &duration
	);

	/**
	\brief Detaches the thread

	This object will give up ownership of the running thread, making it
	impossible to join the thread afterwards. Don't use this function,
	unless you know what you are doing.
	*/
 	FCPPT_THREAD_SYMBOL
	void
	detach();

	/**
	\brief Returns the native handle of the thread

	Returns the native handle of the thread that can be used to access the
	system specific thread API and do additional things that this class
	does not provide.
	*/
	FCPPT_THREAD_SYMBOL
	fcppt::thread::native_handle
	native_handle();

	/**
	\brief Tries to interrupt the thread

	Interrupts the thread as soon as it reaches the next interruption
	point.
	*/
 	FCPPT_THREAD_SYMBOL
	void
	interrupt();

	/**
	\brief Returns if an interruption has been requested

	Returns if an interruption has been requested but the thread has not
	been able to reach an interruption point.*/
	FCPPT_THREAD_SYMBOL
	bool
	interruption_requested() const;

	/**
	\brief Destroys the thread and asserts that it is not joinable

	Asserts that the thread is not joinable, which means that it must have
	either been joined or detached. If this is not the case,
	<code>std::terminate</code> will be called.
	*/
	FCPPT_THREAD_SYMBOL
	~object();
private:
	boost::thread thread_;
};

/**
\brief Swaps two threads

Swaps threads \a left and \a right

\param left The first thread to swap

\param right The second thread to swap
*/
FCPPT_THREAD_SYMBOL
void
swap(
	fcppt::thread::object &left,
	fcppt::thread::object &right
);

}
}

#endif

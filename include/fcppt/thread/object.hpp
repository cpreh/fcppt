//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_THREAD_OBJECT_HPP_INCLUDED
#define FCPPT_THREAD_OBJECT_HPP_INCLUDED

#include <fcppt/thread/id.hpp>
#include <fcppt/thread/join_duration.hpp>
#include <fcppt/thread/native_handle.hpp>
#include <fcppt/thread/task.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/thread/thread.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace thread
{

/// The main thread class
/**
 * It is mostly based on boost::thread.
 * However, the destructor asserts that the thread has been joined.
 * boost::thread detaches the thread instead.
*/
class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	/// Construct the thread and let it immediately run the task
	FCPPT_SYMBOL object(
		thread::task const &
	);

	FCPPT_SYMBOL void
	swap(
		object &
	);

	FCPPT_SYMBOL thread::id
	id() const;

	/// Tells if the thread needs to be joined
	/**
	 * @return true if the thread already has been joined, false otherwise
	*/
	FCPPT_SYMBOL bool
	joinable() const;

	FCPPT_SYMBOL void
	join();

	/// Try to join the thread and block at most for the given duration
	FCPPT_SYMBOL
	bool
	try_join(
		join_duration const &
	);

	/// Detach the thread
	/**
	 * The thread won't be joinable anymore and can roam freely without
	 * you ever getting control over it again. Use this with care.
	*/
 	FCPPT_SYMBOL void
	detach();

	FCPPT_SYMBOL thread::native_handle
	native_handle();

 	FCPPT_SYMBOL void
	interrupt();

	FCPPT_SYMBOL bool
	interruption_requested() const;

	/// asserts that the thread has been joined
	/** Will call std::terminate() if joinable() == true.
	*/
	FCPPT_SYMBOL ~object();
private:
	boost::thread thread_;
};

FCPPT_SYMBOL
void
swap(
	object &,
	object &
);

}
}

#endif // FCPPT_THREAD_OBJECT_HPP_INCLUDED

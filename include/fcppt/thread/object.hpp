//          Copyright Carl Philipp Reh 2009 - 2010.
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
#include <boost/thread/thread.hpp>

namespace fcppt
{
namespace thread
{

class object
{
	FCPPT_NONCOPYABLE(object)
public:
	FCPPT_SYMBOL object(
		thread::task const &
	);

	FCPPT_SYMBOL void
	swap(
		object &
	);

	FCPPT_SYMBOL thread::id
	id() const;

	FCPPT_SYMBOL bool
	joinable() const;

	FCPPT_SYMBOL void
	join();

	FCPPT_SYMBOL
	bool
	try_join(
		join_duration const &
	);

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

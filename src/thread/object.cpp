//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/thread/object.hpp>
#include <exception>

fcppt::thread::object::object(
	task const &_task
)
:
	thread_(
		_task
	)
{
}

void
fcppt::thread::object::swap(
	object &other_
)
{
	thread_.swap(
		other_.thread_
	);
}

fcppt::thread::id
fcppt::thread::object::id() const
{
	return thread_.get_id();
}

bool
fcppt::thread::object::joinable() const
{
	return thread_.joinable();
}

void
fcppt::thread::object::join()
{
	thread_.join();
}

void
fcppt::thread::object::detach()
{
	thread_.detach();
}

fcppt::thread::native_handle
fcppt::thread::object::native_handle()
{
	return thread_.native_handle();
}

void
fcppt::thread::object::interrupt()
{
	thread_.interrupt();
}

bool
fcppt::thread::object::interruption_requested() const
{
	return thread_.interruption_requested();
}

fcppt::thread::object::~object()
{
	if(joinable())
		std::terminate();
}

void
fcppt::thread::swap(
	object &x,
	object &y
)
{
	x.swap(
		y
	);
}

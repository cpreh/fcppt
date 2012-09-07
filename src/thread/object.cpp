//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/thread/id.hpp>
#include <fcppt/thread/join_duration.hpp>
#include <fcppt/thread/native_handle.hpp>
#include <fcppt/thread/object.hpp>
#include <fcppt/thread/task.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


fcppt::thread::object::object(
	fcppt::thread::task const &_task
)
:
	thread_(
		_task
	)
{
}

void
fcppt::thread::object::swap(
	fcppt::thread::object &_other
)
{
	thread_.swap(
		_other.thread_
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

bool
fcppt::thread::object::try_join(
	fcppt::thread::join_duration const &_duration
)
{
	return
		thread_.try_join_for(
			_duration
		);
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
	if(
		this->joinable()
	)
		std::terminate();
}

void
fcppt::thread::swap(
	fcppt::thread::object &_x,
	fcppt::thread::object &_y
)
{
	_x.swap(
		_y
	);
}

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
fcppt::thread::object::join()
{
	thread_.join();
}

fcppt::thread::object::~object()
{
	if (thread_.joinable())
		std::terminate();
}

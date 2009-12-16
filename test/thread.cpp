/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <fcppt/thread/future/packaged_task.hpp>
#include <fcppt/thread/future/shared_object.hpp>
#include <fcppt/thread/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/text.hpp>

namespace
{

bool task()
{
	fcppt::io::cerr << FCPPT_TEXT("sleeping...\n");

	boost::this_thread::sleep(
		boost::posix_time::seconds(3)
	);

	fcppt::io::cerr << FCPPT_TEXT("woke up!\n");
	return true;
}

void void_task()
{
	fcppt::io::cerr << FCPPT_TEXT("sleeping in void\n");

	boost::this_thread::sleep(
		boost::posix_time::seconds(4)
	);

	fcppt::io::cerr << FCPPT_TEXT("void woke up\n");
}

}

int main()
{
	fcppt::thread::future::packaged_task<bool> task_(
		&task
	);

	fcppt::thread::future::shared_object<bool> future_(
		task_.object()
	);
	
	fcppt::io::cerr << FCPPT_TEXT("created future\n");

	fcppt::thread::object thread_(
		std::tr1::ref(
			task_
		)
	);

	fcppt::io::cerr << FCPPT_TEXT("created thread, waiting now\n");

	bool result;

	while (!future_.try_get(result))
		fcppt::io::cerr << FCPPT_TEXT("waiting\n");

	fcppt::io::cerr
		<< FCPPT_TEXT("finished! result: ")
		<< result
		<< FCPPT_TEXT('\n');

	fcppt::io::cerr
		<< FCPPT_TEXT("get again: ")
		<< future_.get()
		<< FCPPT_TEXT('\n');

	fcppt::io::cerr
		<< FCPPT_TEXT("state is: ")
		<< static_cast<int>(future_.state())
		<< FCPPT_TEXT('\n');

	fcppt::io::cerr
		<< FCPPT_TEXT("is_ready: ")
		<< future_.is_ready()
		<< FCPPT_TEXT(", has_exception: ")
		<< future_.has_exception()
		<< FCPPT_TEXT(", has_value: ")
		<< future_.has_value()
		<< FCPPT_TEXT(", was_moved: ")
		<< future_.was_moved()
		<< FCPPT_TEXT('\n');

	thread_.join();
}

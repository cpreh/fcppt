//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[thread
#include <fcppt/thread/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace
{

void
f(
	unsigned const count
)
{
	for(
		unsigned i = 0;
		i < count;
		++i
	)
		std::cout
			<< i
			<< ' ';

	std::cout << '\n';
}

}

int main()
{
	fcppt::thread::object task(
		std::tr1::bind(
			f,
			10
		)
	);

	task.join(); // important, if left out, task's destructor will call std::terminate()!
}
//]

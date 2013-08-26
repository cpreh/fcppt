//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/float_to_int.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


// TODO: Write proper documentation

namespace
{

void
float_to_int()
{
	float const f(
		3.5f
	);

	int const i(
		fcppt::cast::float_to_int<
			int
		>(
			f
		)
	);

	std::cout
		<< i
		<< '\n';
}

}

int
main()
{
	float_to_int();
}

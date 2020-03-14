//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/float_to_int.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
float_to_int()
{
// ![float_to_int]
	float const f(
		3.5F
	);

	int const i(
		fcppt::cast::float_to_int<
			int
		>(
			f
		)
	);

	// prints 3
	std::cout
		<< i
		<< '\n';
// ![float_to_int]
}

// ![to_unsigned]
template<
	typename T
>
void
test(
	T const _t
)
{
	std::cout
		<<
		fcppt::cast::to_unsigned(
			_t
		)
		<< '\n';
}

void
g()
{
	test(
		4
	);

	// error
	/*
	test(
		4u
	);*/
}
// ![to_unsigned]

}

int
main()
{
	float_to_int();

	g();
}

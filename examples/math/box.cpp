//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[mathbox
#include <fcppt/math/box/box.hpp>
#include <iostream>
#include <ostream>

int main()
{
	// declare a two dimensional box (a rect)
	typedef fcppt::math::box::basic<
		unsigned,
		2
	> box2i;

	box2i const box(
		box2i::vector(
			10,
			20
		),
		box2i::dim(
			30,
			30
		)
	);

	std::cout << box << '\n';
}
//]

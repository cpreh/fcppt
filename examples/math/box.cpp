//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[mathbox
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
	// declare a two dimensional box (a rect)
	typedef fcppt::math::box::object<
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

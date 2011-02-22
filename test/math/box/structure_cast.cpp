//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/structure_cast.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	math_box_structure_cast
)
{
	typedef fcppt::math::box::basic<
		float,
		2
	> box_f2;

	typedef fcppt::math::box::basic<
		int,
		2
	> box_i2;

	box_f2 const box1(
		box_f2::vector(
			1.5f,
			2.5f
		),
		box_f2::dim(
			3.5f,
			4.5f
		)
	);

	BOOST_REQUIRE(
		fcppt::math::box::structure_cast<
			box_i2
		>(
			box1
		)
		==
		box_i2(
			box_i2::vector(
				1,
				2
			),
			box_i2::dim(
				3,
				4
			)
		)
	);
}

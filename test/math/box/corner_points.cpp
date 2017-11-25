//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains.hpp>
#include <fcppt/math/box/corner_points.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_box_corner_points
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	box_type box(
		box_type::vector(
			10,
			12
		),
		box_type::dim(24,26)
	);

	std::cout
		<<
		"Checking border points of box: "
		<<
		box
		<<
		'\n';

	typedef
	std::array<
		box_type::vector,
		4
	>
	vertex_array;

	vertex_array const vertices(
		fcppt::math::box::corner_points(
			box
		)
	);

	std::cout
		<<
		"Result: \n";

	for(
		auto const &elem
		:
		vertices
	)
		std::cout
			<<
			elem
			<<
			'\n';

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices,
			box_type::vector(
				10,
				12
			)
		)
	);

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices,
			box_type::vector(
				34,
				12
			)
		)
	);

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices,
			box_type::vector(
				10,
				38
			)
		)
	);

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices,
			box_type::vector(
				34,
				38
			)
		)
	);
}

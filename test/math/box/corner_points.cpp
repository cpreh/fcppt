//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/corner_points.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/algorithm/contains.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(test_corner_points)
{
	typedef
	fcppt::math::box::basic
	<
		int,
		2
	>
	box_type;

	box_type b(
		box_type::vector(10,12),
		box_type::dim(24,26));

	std::cout << "Checking border points of box: " << b << "\n";

	fcppt::container::array<box_type::vector,4> const vertices =
		fcppt::math::box::corner_points(
			b);

	std::cout << "Result: \n";
	BOOST_FOREACH(
		box_type::vector const &v,
		vertices)
		std::cout << v << "\n";

	std::cout << "Running checks now...\n";

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(10,12)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(34,12)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(10,38)));

	BOOST_CHECK(
		fcppt::algorithm::contains(
			vertices.begin(),
			vertices.end(),
			box_type::vector(34,38)));
}

//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/unproject.hpp>
#include <fcppt/math/matrix/orthogonal.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(unproject_test)
{
	double const epsilon =
		0.001;

	typedef
	fcppt::math::matrix::static_<
		double,
		4,
		4
	>::type
	matrix_type;

	typedef
	fcppt::math::box::basic<
		double,
		2
	>
	box_type;

	typedef
	fcppt::math::vector::static_<
		double,
		3
	>::type
	vector3_type;

	matrix_type const
		orthomatrix =
			fcppt::math::matrix::inverse(
				fcppt::math::matrix::orthogonal(
					0.0,
					1.0,
					0.0,
					1.0,
					0.0,
					10.0));

	box_type const viewport(
		box_type::vector(
			0.0,
			0.0),
		box_type::dim(
			1024.0,
			768.0));

	// The center of the screen. Should be projected to 0.5, 0.5
	vector3_type const
		window_coordinates(
			512.0,
			384.0,
			0.0),
		expected_output(
			0.5,
			0.5,
			-5.0);

	std::cout
		<< "Unprojecting the point "
		<< window_coordinates
		<< " using an orthomatrix with the rect ((0,0),(1,1)) with a viewport "
		<< viewport
		<< "\nExpected output is: "
		<< expected_output
		<< "\n";

	vector3_type const result =
		fcppt::math::matrix::unproject(
			window_coordinates,
			orthomatrix,
			viewport);

	std::cout << "Result: " << result << "\n";

	BOOST_CHECK(
		fcppt::math::vector::length(
			result - expected_output) < epsilon);
}

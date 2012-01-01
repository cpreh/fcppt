//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/interpolation/linear.hpp>
#include <fcppt/math/interpolation/trigonometric.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace
{
typedef
fcppt::math::vector::static_<double,2>::type
vector2;

double const epsilon = 0.001;
}

BOOST_AUTO_TEST_CASE(linear_interpolation)
{
	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::linear(
				0.0,
				1.0,
				2.0) - 1.0) < epsilon);

	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::linear(
				1.0,
				1.0,
				2.0) - 2.0) < epsilon);

	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::linear(
				0.5,
				1.0,
				2.0) - 1.5) < epsilon);

	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::linear(
				0.25,
				1.0,
				2.0) - 1.25) < epsilon);

	// One test for vectors
	BOOST_CHECK(
		fcppt::math::vector::length(
			fcppt::math::interpolation::linear(
				0.25,
				vector2(1.0,1.0),
				vector2(2.0,2.0)) - vector2(1.25,1.25)) < epsilon);
}

BOOST_AUTO_TEST_CASE(trigonometric_interpolation)
{
	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::trigonometric(
				0.0,
				1.0,
				2.0) - 1.0) < epsilon);

	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::trigonometric(
				1.0,
				1.0,
				2.0) - 2.0) < epsilon);

	BOOST_CHECK(
		std::abs(
			fcppt::math::interpolation::trigonometric(
				0.5,
				1.0,
				2.0) - 1.5) < epsilon);

	// One test for vectors
	BOOST_CHECK(
		fcppt::math::vector::length(
			fcppt::math::interpolation::trigonometric(
				1.0,
				vector2(1.0,1.0),
				vector2(2.0,2.0)) - vector2(2.0,2.0)) < epsilon);
}

//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/matrix.hpp>
#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(math_matrix_scaling)
{
	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	>::type matrix_type;

	float const epsilon(
		std::numeric_limits<
			float
		>::epsilon()
	);

	matrix_type const trans(
		fcppt::math::matrix::scaling(
			5.f,
			3.f,
			4.f
		)
	);

	BOOST_REQUIRE(
		fcppt::math::matrix::componentwise_equal(
			trans,
			matrix_type(
				5.f, 0.f, 0.f, 0.f,
				0.f, 3.f, 0.f, 0.f,
				0.f, 0.f, 4.f, 0.f,
				0.f, 0.f, 0.f, 1.f
			),
			epsilon
		)
	);

	typedef fcppt::math::vector::static_<
		float,
		4
	>::type vector_type;

	vector_type const vec(
		1.f,
		2.f,
		3.f,
		1.f
	);

	BOOST_REQUIRE(
		fcppt::math::vector::componentwise_equal(
			trans * vec,
			vector_type(
				5.f,
				6.f,
				12.f,
				1.f
			),
			epsilon
		)
	);

}

//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/matrix.hpp>
#include <fcppt/math/matrix/rotation_axis.hpp>
#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/pi.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(math_matrix_rotation_axis)
{
	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	>::type matrix_type;

	typedef fcppt::math::vector::static_<
		float,
		3
	>::type vector_rotation_type;
	
	matrix_type const trans_(
		fcppt::math::matrix::rotation_axis(
			fcppt::math::pi<float>(),
			vector_rotation_type(
				1.f,
				0.f,
				0.f
			)
		)
	);

	typedef fcppt::math::vector::static_<
		float,
		4
	>::type vector_type;

	vector_type const vec_(
		0.f,
		1.f,
		0.f,
		1.f
	);

	BOOST_REQUIRE(
		trans_ * vec_
		==
		vector_type(
			0.f,
			-1.f,
			0.f,
			1.f
		)
	);
}

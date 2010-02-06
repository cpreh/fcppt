//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/matrix.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(math_matrix_translation)
{
	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	>::type matrix_type;
	
	matrix_type const trans_(
		fcppt::math::matrix::translation(
			5.f,
			3.f,
			42.f
		)
	);

	BOOST_REQUIRE(
		trans_
		==
		matrix_type(
			1.f, 0.f, 0.f, 5.f,
			0.f, 1.f, 0.f, 3.f,
			0.f, 0.f, 1.f, 42.f,
			0.f, 0.f, 0.f, 1.f
		)
	);
}

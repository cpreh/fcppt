//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/matrix.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

typedef fcppt::math::matrix::static_<
	int,
	2,
	2
>::type matrix_type;

}

BOOST_AUTO_TEST_CASE(math_matrix_operators_add)
{
	matrix_type const first(
		1, 2,
		3, 4
	);

	matrix_type second(
		2, 3,
		4, 5
	);

	second += first;

	BOOST_REQUIRE(
		second
		== matrix_type(
			3, 5,
			7, 9
		)
	);
}

BOOST_AUTO_TEST_CASE(math_matrix_operators_scalar)
{
	matrix_type first(
		1, 2,
		3, 4
	);

	first *= 3;

	BOOST_REQUIRE(
		first
		== matrix_type(
			3, 6,
			9, 12
		)
	);
}

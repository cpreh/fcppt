//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/matrix.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/utility/enable_if.hpp>

namespace
{

// test overloaded functions

template<
	typename Matrix
>
typename boost::enable_if<
	fcppt::math::matrix::has_dim<
		Matrix,
		1,
		1
	>,
	bool
>::type
is_1x1(
	Matrix const &
)
{
	return true;
}

template<
	typename Matrix
>
typename boost::disable_if<
	fcppt::math::matrix::has_dim<
		Matrix,
		1,
		1
	>,
	bool
>::type
is_1x1(
	Matrix const &
)
{
	return false;
}

}

BOOST_AUTO_TEST_CASE(math_matrix_has_dim)
{

	typedef fcppt::math::matrix::static_<
		float,
		1,
		1
	>::type f1x1;

	f1x1 const m1x1;

	typedef fcppt::math::matrix::static_<
		float,
		2,
		2
	>::type f2x2;

	f2x2 const m2x2;

	BOOST_REQUIRE(
		is_1x1(
			m1x1
		)
	);


	BOOST_REQUIRE(
		!is_1x1(
			m2x2
		)
	);
}

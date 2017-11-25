//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(infinity_norm)
{
	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		3
	>
	matrix_type;

	matrix_type const t(
		fcppt::math::matrix::row(
			3, 5, 7
		),
		fcppt::math::matrix::row(
			2, 6, 4
		),
		fcppt::math::matrix::row(
			0, 2, 8
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::matrix::infinity_norm(
			t
		),
		15
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_adjugate
)
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
			-3, 2, -5
		),
		fcppt::math::matrix::row(
			-1, 0, -2
		),
		fcppt::math::matrix::row(
			3, -4, 1
		)
	);

	matrix_type const result(
		fcppt::math::matrix::adjugate(
			t
		)
	);

	std::cout
		<< result
		<< '\n';

	BOOST_CHECK_EQUAL(
		result,
		matrix_type(
			fcppt::math::matrix::row(
				-8,18,-4
			),
			fcppt::math::matrix::row(
				-5,12,-1
			),
			fcppt::math::matrix::row(
				4,-6,2
			)
		)
	);
}

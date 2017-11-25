//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/logarithm.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_logarithm
)
{
	typedef
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>
	matrix_type;

	matrix_type const t(
		fcppt::math::matrix::row(
			23.6045,-7.38906,23.6045
		),
		fcppt::math::matrix::row(
			-16.2155,14.7781,-23.6045
		),
		fcppt::math::matrix::row(
			30.9936,7.38906,30.9936
		)
	);

	double const epsilon{
		0.1
	};

	BOOST_CHECK((
	        fcppt::math::matrix::componentwise_equal(
			fcppt::math::matrix::logarithm(
				t,
				1e-4,
				1.0e-9,
				1.0e-6
			),
		        matrix_type(
				fcppt::math::matrix::row(
					2.0, -1.0, 1.0
				),
				fcppt::math::matrix::row(
					0.0, 3.0, -1.0
				),
				fcppt::math::matrix::row(
					2.0, 1.0, 3.0
				)
			),
		        epsilon
		)
	));
}

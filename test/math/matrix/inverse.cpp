//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::inverse",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>
	large_matrix_type;

	CHECK(
		fcppt::math::matrix::componentwise_equal(
			fcppt::math::matrix::inverse(
				large_matrix_type(
					fcppt::math::matrix::row(
						0.,1.,2.
					),
					fcppt::math::matrix::row(
						1.,0.,3.
					),
					fcppt::math::matrix::row(
						4.,-3.,8.
					)
				)
			),
			large_matrix_type(
				fcppt::math::matrix::row(
					-9./2.,7.,-3./2.
				),
				fcppt::math::matrix::row(
					-2.,4.,-1.
				),
				fcppt::math::matrix::row(
					3./2.,-2.,1./2.
				)
			),
			std::numeric_limits<
				double
			>::epsilon()
		)
	);
}

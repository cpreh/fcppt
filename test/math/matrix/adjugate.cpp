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
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::adjugate",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		3
	>
	matrix_type;

	CHECK(
		fcppt::math::matrix::adjugate(
			matrix_type{
				fcppt::math::matrix::row(
					-3, 2, -5
				),
				fcppt::math::matrix::row(
					-1, 0, -2
				),
				fcppt::math::matrix::row(
					3, -4, 1
				)
			}
		)
		==
		matrix_type{
			fcppt::math::matrix::row(
				-8,18,-4
			),
			fcppt::math::matrix::row(
				-5,12,-1
			),
			fcppt::math::matrix::row(
				4,-6,2
			)
		}
	);
}

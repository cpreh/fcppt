//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/infinity_norm.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::infinity_norm",
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
		fcppt::math::matrix::infinity_norm(
			matrix_type{
				fcppt::math::matrix::row(
					3, 5, 7
				),
				fcppt::math::matrix::row(
					2, 6, 4
				),
				fcppt::math::matrix::row(
					0, 2, 8
				)
			}
		)
		==
		15
	);
}

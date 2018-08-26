//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed_fun.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::structure_cast",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::matrix::static_<
		unsigned,
		2,
		2
	>
	ui2_matrix;

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	i2_matrix;

	CHECK(
		i2_matrix{
			fcppt::math::matrix::row(
				1, 2
			),
			fcppt::math::matrix::row(
				3, 4
			)
		}
		==
		fcppt::math::matrix::structure_cast<
			i2_matrix,
			fcppt::cast::to_signed_fun
		>(
			ui2_matrix(
				fcppt::math::matrix::row(
					1u, 2u
				),
				fcppt::math::matrix::row(
					3u, 4u
				)
			)
		)
	);
}

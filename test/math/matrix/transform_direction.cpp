//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/matrix/transform_direction.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::transform_direction",
	"[math],[matrix]"
)
{
	using
	vector_type
	=
	fcppt::math::vector::static_<
		int,
		3
	>;

	CHECK(
		fcppt::math::matrix::transform_direction(
			fcppt::math::matrix::scaling(
				1,
				2,
				3
			),
			vector_type(
				4,
				5,
				6
			)
		)
		==
		vector_type(
			4,
			10,
			18
		)
	);
}

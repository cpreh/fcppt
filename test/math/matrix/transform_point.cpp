//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/transform_point.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::transform_point",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	vector_type;

	CHECK(
		fcppt::math::matrix::transform_point(
			fcppt::math::matrix::translation(
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
			5,
			7,
			9
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/intersection.hpp>
#include <fcppt/math/box/null.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::intersection",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_i2;

	box_i2 const
		box1(
			box_i2::vector(
				1,
				1
			),
			box_i2::dim(
				2,
				2
			)
		),
		box2(
			box_i2::vector(
				0,
				0
			),
			box_i2::dim(
				4,
				4
			)
		),
		box3(
			box_i2::vector(
				2,
				2
			),
			box_i2::dim(
				2,
				2
			)
		),
		box4(
			box_i2::vector(
				5,
				5
			),
			box_i2::dim(
				1,
				1
			)
		),
		intersection1(
			fcppt::math::box::intersection(
				box1,
				box2
			)
		),
		intersection2(
			fcppt::math::box::intersection(
				box1,
				box3
			)
		),
		intersection3(
			fcppt::math::box::intersection(
				box1,
				box4
			)
		);

	CHECK(
		intersection1
		==
		box1
	);

	box_i2 const result2(
		box_i2::vector(
			2,
			2
		),
		box_i2::dim(
			1,
			1
		)
	);

	CHECK(
		intersection2
		==
		result2
	);

	CHECK(
		intersection3
		==
		fcppt::math::box::null<
			box_i2
		>()
	);
}

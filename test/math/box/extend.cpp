//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/extend_bounding_box.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::extend_bounding_box vector",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	box_type box(
		box_type::vector(
			1,
			1
		),
		box_type::dim(
			0,
			0
		)
	);

	box =
		fcppt::math::box::extend_bounding_box(
			box,
			box_type::vector(
				3,
				4
			)
		);

	REQUIRE(
		box
		==
		box_type(
			box_type::vector(
				1,
				1
			),
			box_type::dim(
				2,
				3
			)
		)
	);

	box =
		fcppt::math::box::extend_bounding_box(
			box,
			box_type::vector(
				0,0
			)
		);

	REQUIRE(
		box
		==
		box_type(
			box_type::vector(
				0,
				0
			),
			box_type::dim(
				3,
				4
			)
		)
	);

	// This point is inside the bounding box -> nothing should change
	box =
		fcppt::math::box::extend_bounding_box(
			box,
			box_type::vector(
				1,
				1
			)
		);

	REQUIRE(
		box
		==
		box_type(
			box_type::vector(
				0,
				0
			),
			box_type::dim(
				3,
				4
			)
		)
	);
}

TEST_CASE(
	"math::box::extend_bounding_box box",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	box_type const box1(
		box_type::vector(
			1,
			2
		),
		box_type::dim(
			2,
			3
		)
	);

	box_type const box2(
		box_type::vector(
			0,
			1
		),
		box_type::dim(
			2,
			1
		)
	);

	box_type const expected(
		box_type::vector(
			0,
			1
		),
		box_type::dim(
			3,
			4
		)
	);

	CHECK(
		fcppt::math::box::extend_bounding_box(
			box1,
			box2
		)
		==
		expected
	);

	CHECK(
		fcppt::math::box::extend_bounding_box(
			box2,
			box1
		)
		==
		expected
	);
}

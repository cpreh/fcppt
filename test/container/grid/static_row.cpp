//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/static_row.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::static_row",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	int2_grid const grid{
		fcppt::container::grid::static_row(
			1, 2
		),
		fcppt::container::grid::static_row(
			3, 4
		)
	};

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				0u, 0u
			)
		)
		==
		1
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				1u, 0u
			)
		)
		==
		2
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				0u, 1u
			)
		)
		==
		3
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				1u, 1u
			)
		)
		==
		4
	);
}

TEST_CASE(
	"container::grid::static_row move",
	"[container],[grid]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	fcppt::container::grid::object<
		int_movable,
		2
	>
	int2_grid;

	int2_grid const grid{
		fcppt::container::grid::static_row(
			int_movable(1),
			int_movable(2)
		),
		fcppt::container::grid::static_row(
			int_movable(3),
			int_movable(4)
		)
	};

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				0u, 0u
			)
		)
		==
		int_movable(1)
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				1u, 0u
			)
		)
		==
		int_movable(2)
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				0u, 1u
			)
		)
		==
		int_movable(3)
	);

	CHECK(
		grid.get_unsafe(
			int2_grid::pos(
				1u, 1u
			)
		)
		==
		int_movable(4)
	);
}

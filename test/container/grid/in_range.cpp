//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/in_range.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::in_range",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	int2_grid const test(
		int2_grid::dim(
			3u,
			4u
		),
		0
	);

	typedef
	int2_grid::pos
	pos;

	CHECK(
		fcppt::container::grid::in_range(
			test,
			pos(
				2u,
				2u
			)
		)
	);

	CHECK_FALSE(
		fcppt::container::grid::in_range(
			test,
			pos(
				3u,
				2u
			)
		)
	);

	CHECK_FALSE(
		fcppt::container::grid::in_range(
			test,
			pos(
				2u,
				4U
			)
		)
	);
}

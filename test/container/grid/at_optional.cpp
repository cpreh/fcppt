//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/at_optional.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::at_optional",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	int2_grid grid(
		int2_grid::dim{
			2u,
			3u
		},
		0
	);

	CHECK(
		fcppt::container::grid::at_optional(
			grid,
			int2_grid::pos(
				1u,
				2u
			)
		).has_value()
	);

	CHECK_FALSE(
		fcppt::container::grid::at_optional(
			grid,
			int2_grid::pos(
				2u,
				2u
			)
		).has_value()
	);

	int2_grid const const_grid(
		grid
	);

	CHECK(
		fcppt::container::grid::at_optional(
			const_grid,
			int2_grid::pos(
				1u,
				2u
			)
		).has_value()
	);
}

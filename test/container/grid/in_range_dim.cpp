//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/in_range_dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::in_range_dim",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::pos<
		std::size_t,
		2u
	>
	int2_pos;

	typedef
	fcppt::container::grid::dim<
		std::size_t,
		2u
	>
	int2_dim;

	int2_dim const test{
		3u,
		4u
	};

	CHECK(
		fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				2u,
				2u
			)
		)
	);

	CHECK_FALSE(
		fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				3u,
				2u
			)
		)
	);

	CHECK_FALSE(
		fcppt::container::grid::in_range_dim(
			test,
			int2_pos(
				2u,
				4U
			)
		)
	);
}

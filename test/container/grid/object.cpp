//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <catch2/catch.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::grid::object<
	int,
	2
>
int2_grid;

}

TEST_CASE(
	"container::grid init reference",
	"[container],[grid]"
)
{
	int2_grid const test(
		int2_grid::dim(
			10u,
			20u
		),
		42
	);

	CHECK(
		std::count(
			test.begin(),
			test.end(),
			42
		)
		==
		200
	);
}

TEST_CASE(
	"container::grid index 2d",
	"[container],[grid]"
)
{
	int2_grid const test(
		int2_grid::dim(
			5u,
			10u
		),
		[](
			int2_grid::pos
		)
		{
			static int entry{
				0
			};

			return
				entry++;
		}
	);

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size().h()
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size().w()
			)
		)
		{
			CHECK(
				test.get_unsafe(
					int2_grid::pos(
						x,
						y
					)
				)
				==
				fcppt::cast::size<
					int2_grid::value_type
				>(
					fcppt::cast::to_signed(
						x + y * 5
					)
				)
			);
		}
}

TEST_CASE(
	"container::grid index 3d",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::object<
		int,
		3
	>
	int3_grid;

	int3_grid const test(
		int3_grid::dim(
			5u,
			10u,
			8u
		),
		[](
			int3_grid::pos
		)
		{
			static int entry{
				0
			};

			return
				entry++;
		}
	);

	for(
		auto const z
		:
		fcppt::make_int_range_count(
			test.size().d()
		)
	)
		for(
			auto const y
			:
			fcppt::make_int_range_count(
				test.size().h()
			)
		)
			for(
				auto const x
				:
				fcppt::make_int_range_count(
					test.size().w()
				)
			)
			{
				CHECK(
					test.get_unsafe(
						int3_grid::pos(
							x,
							y,
							z
						)
					)
					==
					fcppt::cast::size<
						int3_grid::value_type
					>(
						fcppt::cast::to_signed(
							x + y * 5 + z * 5 * 10
						)
					)
				);
			}
}

TEST_CASE(
	"container::grid const data",
	"[container],[grid]"
)
{
	int2_grid const test(
		int2_grid::dim(
			5u,
			2u
		),
		42
	);

	CHECK(
		std::count(
			test.begin(),
			test.end(),
			42
		)
		==
		10
	);
}

TEST_CASE(
	"container::grid::contents",
	"[container],[grid]"
)
{
	int2_grid const test(
		int2_grid::dim(
			3u,
			2u
		),
		0
	);

	CHECK(
		test.content()
		==
		6u
	);
}

TEST_CASE(
	"container::grid move",
	"[container],[grid]"
)
{
	int2_grid grid1(
		int2_grid::dim(
			2u,
			3u
		),
		0
	);

	grid1.get_unsafe(
		int2_grid::pos(
			0u,
			0u
		)
	)
		= 1;

	grid1.get_unsafe(
		int2_grid::pos(
			1u,
			1u
		)
	)
		= 2;

	int2_grid grid2(
		std::move(
			grid1
		)
	);

	REQUIRE(
		grid2.size()
		==
		int2_grid::dim(
			2u,
			3u
		)
	);

	CHECK(
		grid2.get_unsafe(
			int2_grid::pos(
				0u,
				0u
			)
		)
		==
		1
	);

	CHECK(
		grid2.get_unsafe(
			int2_grid::pos(
				1u,
				1u
			)
		)
		==
		2
	);

	CHECK(
		grid1.begin()
		==
		grid1.end()
	);

	int2_grid grid3;

	grid3 =
		std::move(
			grid2
		);

	REQUIRE(
		grid3.size()
		==
		int2_grid::dim(
			2u,
			3u
		)
	);

	CHECK(
		grid3.get_unsafe(
			int2_grid::pos(
				0u,
				0u
			)
		)
		==
		1
	);

	CHECK(
		grid3.get_unsafe(
			int2_grid::pos(
				1u,
				1u
			)
		)
		==
		2
	);

	CHECK(
		grid2.begin()
		==
		grid2.end()
	);
}

TEST_CASE(
	"container::grid init",
	"[container],[grid]"
)
{
	int2_grid const grid(
		int2_grid::dim(
			2u,
			3u
		),
		[](
			int2_grid::pos const _pos
		)
		{
			return
				fcppt::cast::size<
					int
				>(
					fcppt::cast::to_signed(
						_pos.x()
						*
						_pos.y()
					)
				);
		}
	);

	typedef
	int2_grid::pos
	pos;

	REQUIRE(
		fcppt::cast::to_signed(
			grid.content()
		)
		==
		std::distance(
			grid.begin(),
			grid.end()
		)
	);

	CHECK(
		grid.get_unsafe(
			pos(
				0u,
				0u
			)
		)
		==
		0
	);

	CHECK(
		grid.get_unsafe(
			pos(
				1u,
				2u
			)
		)
		==
		2
	);
}

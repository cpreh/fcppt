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
#include <boost/test/unit_test.hpp>
#include <algorithm>
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

BOOST_AUTO_TEST_CASE(
	container_grid_init_reference
)
{
	int2_grid const test(
		int2_grid::dim(
			10u,
			20u
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::count(
			test.begin(),
			test.end(),
			42
		),
		200
	);
}

BOOST_AUTO_TEST_CASE(
	container_grid_index_2d
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
			BOOST_REQUIRE_EQUAL(
				test.get_unsafe(
					int2_grid::pos(
						x,
						y
					)
				),
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

BOOST_AUTO_TEST_CASE(
	container_grid_index_3d
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
				BOOST_CHECK_EQUAL(
					test.get_unsafe(
						int3_grid::pos(
							x,
							y,
							z
						)
					),
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

BOOST_AUTO_TEST_CASE(
	container_grid_const_data
)
{
	int2_grid const test(
		int2_grid::dim(
			5u,
			2u
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::count(
			test.begin(),
			test.end(),
			42
		),
		10
	);
}

BOOST_AUTO_TEST_CASE(
	container_grid_size
)
{
	int2_grid const test(
		int2_grid::dim(
			3u,
			2u
		),
		0
	);

	BOOST_CHECK_EQUAL(
		test.content(),
		6u
	);
}

BOOST_AUTO_TEST_CASE(
	container_grid_move
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

	BOOST_CHECK_EQUAL(
		grid2.size(),
		int2_grid::dim(
			2u,
			3u
		)
	);

	BOOST_CHECK_EQUAL(
		grid2.get_unsafe(
			int2_grid::pos(
				0u,
				0u
			)
		),
		1
	);

	BOOST_CHECK_EQUAL(
		grid2.get_unsafe(
			int2_grid::pos(
				1u,
				1u
			)
		),
		2
	);

	BOOST_CHECK(
		grid1.begin()
		==
		grid1.end()
	);

	int2_grid grid3;

	grid3 =
		std::move(
			grid2
		);

	BOOST_CHECK_EQUAL(
		grid3.size(),
		int2_grid::dim(
			2u,
			3u
		)
	);

	BOOST_CHECK_EQUAL(
		grid3.get_unsafe(
			int2_grid::pos(
				0u,
				0u
			)
		),
		1
	);

	BOOST_CHECK_EQUAL(
		grid3.get_unsafe(
			int2_grid::pos(
				1u,
				1u
			)
		),
		2
	);

	BOOST_CHECK(
		grid2.begin()
		==
		grid2.end()
	);
}

BOOST_AUTO_TEST_CASE(
	container_grid_init_function
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

	BOOST_CHECK_EQUAL(
		fcppt::cast::to_signed(
			grid.content()
		),
		std::distance(
			grid.begin(),
			grid.end()
		)
	);

	BOOST_CHECK_EQUAL(
		grid.get_unsafe(
			pos(
				0u,
				0u
			)
		),
		0
	);

	BOOST_CHECK_EQUAL(
		grid.get_unsafe(
			pos(
				1u,
				2u
			)
		),
		2
	);
}

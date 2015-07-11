//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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

struct nonpod
{
	nonpod()
	:
		member_(
			42
		)
	{
	}

	int member_;
};

}

template
class
fcppt::container::grid::object<
	int,
	2
>;

template
class
fcppt::container::grid::object<
	int,
	3
>;

template
class
fcppt::container::grid::object<
	nonpod,
	2
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_init_reference
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			10,
			20
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_index_2d
)
{
FCPPT_PP_POP_WARNING

	int2_grid test(
		int2_grid::dim(
			5,
			10
		),
		fcppt::no_init{}
	);

	{
		int entry = 0;

		for(
			int2_grid::pointer ptr = test.data();
			ptr != test.data_end();
			++ptr
		)
			*ptr = entry++;
	}

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size()[1]
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size()[0]
			)
		)
			BOOST_REQUIRE_EQUAL(
				test[
					int2_grid::pos(
						x,
						y
					)
				],
				fcppt::cast::size<
					int2_grid::value_type
				>(
					fcppt::cast::to_signed(
						x + y * 5
					)
				)
			);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_index_3d
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		int,
		3
	>
	int3_grid;

	int3_grid test(
		int3_grid::dim(
			5,
			10,
			8
		),
		fcppt::no_init{}
	);

	{
		int entry{
			0
		};

		for(
			int3_grid::pointer ptr = test.data();
			ptr != test.data_end();
			++ptr
		)
			*ptr = entry++;
	}

	for(
		auto const z
		:
		fcppt::make_int_range_count(
			test.size()[2]
		)
	)
		for(
			auto const y
			:
			fcppt::make_int_range_count(
				test.size()[1]
			)
		)
			for(
				auto const x
				:
				fcppt::make_int_range_count(
					test.size()[0]
				)
			)
				BOOST_CHECK_EQUAL(
					test[
						int3_grid::pos(
							x,
							y,
							z
						)
					],
					fcppt::cast::size<
						int3_grid::value_type
					>(
						fcppt::cast::to_signed(
							x + y * 5 + z * 5 * 10
						)
					)
				);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_const_data
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			5,
			2
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::count(
			test.data(),
			test.data_end(),
			42
		),
		10
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_size
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			3,
			2
		),
		fcppt::no_init{}
	);

	BOOST_CHECK_EQUAL(
		test.content(),
		6u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_non_pod
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		nonpod,
		2
	>
	grid2_nonpod;

	grid2_nonpod const test(
		grid2_nonpod::dim(
			5,
			3
		),
		nonpod()
	);

	for(
		auto const &element
		:
		test
	)
		BOOST_CHECK_EQUAL(
			element.member_,
			42
		);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_resize
)
{
FCPPT_PP_POP_WARNING

	int2_grid test(
		int2_grid::dim(
			10,
			5
		),
		fcppt::no_init{}
	);

	test.resize(
		int2_grid::dim(
			5,
			3
		),
		fcppt::no_init{}
	);

	BOOST_CHECK_EQUAL(
		test.size(),
		int2_grid::dim(
			5,
			3
		)
	);

	BOOST_CHECK_EQUAL(
		std::distance(
			test.data(),
			test.data_end()
		),
		fcppt::cast::to_signed(
			test.size().content()
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_move
)
{
FCPPT_PP_POP_WARNING

	int2_grid grid1(
		int2_grid::dim(
			2,
			3
		),
		fcppt::no_init{}
	);

	grid1[
		int2_grid::pos(
			0,
			0
		)
	] = 1;

	grid1[
		int2_grid::pos(
			1,
			1
		)
	] = 2;

	int2_grid grid2(
		std::move(
			grid1
		)
	);

	BOOST_CHECK(
		grid2.size()
		==
		int2_grid::dim(
			2,
			3
		)
	);

	BOOST_CHECK(
		grid2[
			int2_grid::pos(
				0,
				0
			)
		] == 1
	);

	BOOST_CHECK(
		grid2[
			int2_grid::pos(
				1,
				1
			)
		] == 2
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

	BOOST_CHECK(
		grid3.size()
		==
		int2_grid::dim(
			2,
			3
		)
	);

	BOOST_CHECK(
		grid3[
			int2_grid::pos(
				0,
				0
			)
		] == 1
	);

	BOOST_CHECK(
		grid3[
			int2_grid::pos(
				1,
				1
			)
		] == 2
	);

	BOOST_CHECK(
		grid2.begin()
		==
		grid2.end()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_init_function
)
{
FCPPT_PP_POP_WARNING
	int2_grid const grid(
		int2_grid::dim(
			2,
			3
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
			grid.size().content()
		),
		std::distance(
			grid.begin(),
			grid.end()
		)
	);

	BOOST_CHECK_EQUAL(
		grid[
			pos(
				0,
				0
			)
		],
		0
	);

	BOOST_CHECK_EQUAL(
		grid[
			pos(
				1,
				2
			)
		],
		2
	);
}

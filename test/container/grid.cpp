//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/comparison.hpp>
#include <fcppt/container/grid/fill.hpp>
#include <fcppt/container/grid/in_range.hpp>
#include <fcppt/container/grid/is_square.hpp>
#include <fcppt/container/grid/iterator_position.hpp>
#include <fcppt/container/grid/make_pos_crange.hpp>
#include <fcppt/container/grid/make_pos_range.hpp>
#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/resize_preserve.hpp>
#include <fcppt/container/grid/resize_preserve_init.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2_grid;

typedef fcppt::container::grid::object<
	int,
	2
> uint2_grid;

typedef fcppt::container::grid::object<
	int,
	3
> int3_grid;

struct nonpod
{
	nonpod()
	:
		member_(
			42
		)
	{}

	int member_;
};

typedef fcppt::container::grid::object<
	nonpod,
	2
> grid2_nonpod;

typedef fcppt::container::grid::object<
	std::pair<
		fcppt::container::grid::size_type,
		fcppt::container::grid::size_type
	>,
	2
> sz_pair_grid;

}

template class fcppt::container::grid::object<
	int,
	2
>;

template class fcppt::container::grid::object<
	unsigned,
	2
>;

template class fcppt::container::grid::object<
	int,
	3
>;

template class fcppt::container::grid::object<
	nonpod,
	2
>;

template class fcppt::container::grid::object<
	std::pair<
		fcppt::container::grid::size_type,
		fcppt::container::grid::size_type
	>,
	2
>;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_init
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

	BOOST_REQUIRE(
		std::count(
			test.begin(),
			test.end(),
			42
		)
		== 200
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_iterator_position
)
{
FCPPT_PP_POP_WARNING

	int2_grid const grid(
		int2_grid::dim(2,2));

	int2_grid::const_iterator it =
		grid.begin();

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::pos(0,0));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::pos(1,0));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::pos(0,1));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::pos(1,1));
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_compare
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test1(
		int2_grid::dim(
			5,
			10
		),
		0
	);

	int2_grid test2(
		int2_grid::dim(
			10,
			2
		),
		0
	);

	BOOST_CHECK(
		test1 != test2
	);

	BOOST_CHECK(
		test1 < test2
	);

	BOOST_CHECK(
		test1 <= test2
	);

	BOOST_CHECK(
		!(test1 > test2)
	);

	BOOST_CHECK(
		!(test1 >= test2)
	);

	test2 = test1;

	BOOST_CHECK(
		test1 == test2
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
		)
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
		int2_grid::dim::size_type y = 0;
		y < test.size()[1];
		++y
	)
		for(
			int2_grid::dim::size_type x = 0;
			x < test.size()[0];
			++x
		)
			BOOST_REQUIRE(
				test[
					int2_grid::pos(
						x,
						y
					)
				]
				==
				static_cast<
					int2_grid::value_type
				>(
					x + y * 5
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

	int3_grid test(
		int3_grid::dim(
			5,
			10,
			8
		)
	);

	{
		int entry = 0;

		for(
			int3_grid::pointer ptr = test.data();
			ptr != test.data_end();
			++ptr
		)
			*ptr = entry++;
	}

	for(
		int3_grid::dim::size_type z = 0;
		z < test.size()[2];
		++z
	)
		for(
			int3_grid::dim::size_type y = 0;
			y < test.size()[1];
			++y
		)
			for(
				int3_grid::dim::size_type x = 0;
				x < test.size()[0];
				++x
			)
				BOOST_REQUIRE(
					test[
						int3_grid::pos(
							x,
							y,
							z
						)
					]
					==
					static_cast<
						int3_grid::value_type
					>(
						x + y * 5 + z * 5 * 10
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

	BOOST_REQUIRE(
		std::count(
			test.data(),
			test.data_end(),
			42
		) == 10
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
		)
	);

	BOOST_REQUIRE(
		test.content() == 6u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_non_pod
)
{
FCPPT_PP_POP_WARNING

	grid2_nonpod const test(
		grid2_nonpod::dim(
			5,
			3
		),
		nonpod()
	);

	for(
		grid2_nonpod::const_iterator it(
			test.begin()
		);
		it != test.end();
		++it
	)
		BOOST_REQUIRE(
			it->member_ == 42
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
		)
	);

	test.resize(
		int2_grid::dim(
			5,
			3
		)
	);

	BOOST_REQUIRE(
		test.size()
		==
		int2_grid::dim(
			5,
			3
		)
	);

	BOOST_REQUIRE(
		std::distance(
			test.data(),
			test.data_end()
		)
		== static_cast<
			int2_grid::difference_type
		>(
			test.size().content()
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_resize_preverse
)
{
FCPPT_PP_POP_WARNING

	sz_pair_grid test(
		sz_pair_grid::dim(
			5,
			10
		)
	);

	for(
		sz_pair_grid::dim::size_type y = 0;
		y < test.size()[1];
		++y
	)
		for(
			sz_pair_grid::dim::size_type x = 0;
			x < test.size()[0];
			++x
		)
			test[
				sz_pair_grid::pos(
					x,
					y
				)
			]
				= std::make_pair(
					x,
					y
				);

	fcppt::container::grid::resize_preserve(
		test,
		sz_pair_grid::dim(
			3,
			5
		)
	);

	BOOST_REQUIRE(
		test.size()
		==
		sz_pair_grid::dim(
			3,
			5
		)
	);

	for(
		sz_pair_grid::dim::size_type y = 0;
		y < test.size()[1];
		++y
	)
		for(
			sz_pair_grid::dim::size_type x = 0;
			x < test.size()[0];
			++x
		)
		{
			BOOST_REQUIRE(
				test[
					sz_pair_grid::pos(
						x,
						y
					)
				]
				== std::make_pair(
					x,
					y
				)
			);
		}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_resize_preverse_init
)
{
FCPPT_PP_POP_WARNING

	sz_pair_grid test(
		sz_pair_grid::dim(
			5,
			10
		)
	);

	for(
		sz_pair_grid::dim::size_type y = 0;
		y < test.size()[1];
		++y
	)
		for(
			sz_pair_grid::dim::size_type x = 0;
			x < test.size()[0];
			++x
		)
			test[
				sz_pair_grid::pos(
					x,
					y
				)
			]
				= std::make_pair(
					x,
					y
				);

	fcppt::container::grid::resize_preserve_init(
		test,
		sz_pair_grid::dim(
			10,
			15
		),
		sz_pair_grid::value_type(
			10u,
			20u
		)
	);

	BOOST_REQUIRE(
		test.size()
		==
		sz_pair_grid::dim(
			10,
			15
		)
	);

	for(
		sz_pair_grid::dim::size_type y = 0;
		y < test.size()[1];
		++y
	)
		for(
			sz_pair_grid::dim::size_type x = 0;
			x < test.size()[0];
			++x
		)
		{
			if(
				x < 5 && y < 10
			)
				BOOST_REQUIRE(
					test[
						sz_pair_grid::pos(
							x,
							y
						)
					]
					== std::make_pair(
						x,
						y
					)
				);
			else
				BOOST_REQUIRE(
					test[
						sz_pair_grid::pos(
							x,
							y
						)
					]
					==
					sz_pair_grid::value_type(
						10u,
						20u
					)
				);
		}
}

namespace
{
int
fill_functor(
	int2_grid::pos const &v)
{
	return
		std::accumulate(
			v.begin(),
			v.end(),
			0);
}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_fill
)
{
FCPPT_PP_POP_WARNING

	int2_grid test(
		(
		int2_grid::dim(
			2,
			2
		))
	);

	fcppt::container::grid::fill(
		test,
		&fill_functor);

	BOOST_REQUIRE(
		test[int2_grid::pos(0,0)] == 0 &&
		test[int2_grid::pos(1,0)] == 1 &&
		test[int2_grid::pos(0,1)] == 1 &&
		test[int2_grid::pos(1,1)] == 2
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_in_range
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			3,
			4
		)
	);

	BOOST_CHECK(
		fcppt::container::grid::in_range(
			test,
			int2_grid::pos(
				2,
				2
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range(
			test,
			int2_grid::pos(
				3,
				2
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range(
			test,
			int2_grid::pos(
				2,
				4
			)
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_is_square
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		fcppt::container::grid::is_square(
			int2_grid(
				int2_grid::dim(
					5,
					5))));

	BOOST_CHECK(
		!fcppt::container::grid::is_square(
			int2_grid(
				int2_grid::dim(
					4,
					5))));
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
		)
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
	container_grid_pos_range
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::pos<
		std::size_t,
		2
	>
	dim;

	typedef
	fcppt::container::grid::object<
		dim,
		2
	>
	dim2_grid;

	dim2_grid grid(
		dim2_grid::dim(
			4,
			6
		)
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_range(
			grid
		)
	)
		element.value()
		=
		element.pos();

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_crange(
			grid
		)
	)
		BOOST_CHECK(
			element.value()
			==
			element.pos()
		);

	bool loop_empty(
		true
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_range_start_end(
			grid,
			dim2_grid::pos::null(),
			dim2_grid::pos::null()
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_range_start_end(
			grid,
			dim2_grid::pos::null(),
			dim2_grid::pos(0, 1)
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_range_start_end(
			grid,
			dim2_grid::pos::null(),
			dim2_grid::pos(1, 0)
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);
}

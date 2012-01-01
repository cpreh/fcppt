//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/grid.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <utility>
#include <vector>
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

BOOST_AUTO_TEST_CASE(container_grid_init)
{
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

BOOST_AUTO_TEST_CASE(container_grid_iterator)
{
	typedef std::vector<
		int
	> int_vector;

	int_vector const vec(10, 42);

	int2_grid const test(
		int2_grid::dim(
			5,
			2
		),
		vec.begin(),
		vec.end()
	);

	BOOST_REQUIRE(
		std::count(
			test.begin(),
			test.end(),
			42
		) == 10
	);
}

BOOST_AUTO_TEST_CASE(container_grid_iterator_position)
{
	int2_grid const grid(
		int2_grid::dim(2,2));

	int2_grid::const_iterator it =
		grid.begin();

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::dim(0,0));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::dim(1,0));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::dim(0,1));

	BOOST_CHECK(
		fcppt::container::grid::iterator_position(
			grid,
			it++) ==
		int2_grid::dim(1,1));
}

BOOST_AUTO_TEST_CASE(container_grid_compare)
{
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

BOOST_AUTO_TEST_CASE(container_grid_index_2d)
{
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
					int2_grid::dim(
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

BOOST_AUTO_TEST_CASE(container_grid_index_3d)
{
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
						int3_grid::dim(
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

BOOST_AUTO_TEST_CASE(container_grid_const_data)
{
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

BOOST_AUTO_TEST_CASE(container_grid_size)
{
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

BOOST_AUTO_TEST_CASE(container_grid_non_pod)
{
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

BOOST_AUTO_TEST_CASE(container_grid_resize)
{
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

BOOST_AUTO_TEST_CASE(container_grid_resize_preverse)
{
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
				sz_pair_grid::dim(
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
					sz_pair_grid::dim(
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

BOOST_AUTO_TEST_CASE(container_grid_resize_preverse_init)
{
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
				sz_pair_grid::dim(
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
						sz_pair_grid::dim(
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
						sz_pair_grid::dim(
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
	int2_grid::dim const &v)
{
	return
		std::accumulate(
			v.begin(),
			v.end(),
			0);
}
}

BOOST_AUTO_TEST_CASE(container_grid_fill)
{
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
		test[int2_grid::dim(0,0)] == 0 &&
		test[int2_grid::dim(1,0)] == 1 &&
		test[int2_grid::dim(0,1)] == 1 &&
		test[int2_grid::dim(1,1)] == 2
	);
}

BOOST_AUTO_TEST_CASE(
	container_grid_in_range
)
{
	int2_grid const test(
		int2_grid::dim(
			3,
			4
		)
	);

	BOOST_CHECK(
		fcppt::container::grid::in_range(
			test,
			int2_grid::dim(
				2,
				2
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range(
			test,
			int2_grid::dim(
				3,
				2
			)
		)
	);

	BOOST_CHECK(
		!fcppt::container::grid::in_range(
			test,
			int2_grid::dim(
				2,
				4
			)
		)
	);
}

BOOST_AUTO_TEST_CASE(
	container_is_square
)
{
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

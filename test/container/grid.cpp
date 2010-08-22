//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/grid.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>
#include <algorithm>
#include <vector>

namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2_grid;

}

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

BOOST_AUTO_TEST_CASE(container_grid_index)
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
		y < test.dimension()[1];
		++y
	)
		for(
			int2_grid::dim::size_type x = 0;
			x < test.dimension()[0];
			++x
		)
			BOOST_REQUIRE(
				test[
					int2_grid::dim(
						x,
						y	
					)
				]
				== (x + y * 5)
			);
}

namespace
{

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

}

BOOST_AUTO_TEST_CASE(container_grid_non_pod)
{
	typedef fcppt::container::grid::object<
		nonpod,
		2
	> grid2;

	grid2 const test(
		grid2::dim(
			5,
			3
		),
		nonpod()
	);

	BOOST_FOREACH(
		grid2::const_reference elem,
		test
	)
		BOOST_REQUIRE(
			elem.member_ == 42
		);
}

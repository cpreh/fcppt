//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/grid.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2_grid;

void
test_const(
	int2_grid const &_grid
)
{
	BOOST_REQUIRE(
		_grid[
			int2_grid::dim(
				5,
				10	
			)
		]
		== 42
	);
}
	
}

BOOST_AUTO_TEST_CASE(container_grid)
{
	int2_grid test(
		int2_grid::dim(
			10,
			20
		)
	);

	test[
		int2_grid::dim(
			5,
			10
		)
	] = 42;

	::test_const(
		test
	);
}

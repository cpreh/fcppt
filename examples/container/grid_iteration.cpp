//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

//! [grid_iteration]

namespace
{
typedef fcppt::container::grid::object<
	int,
	1
> int1d_grid;

typedef fcppt::container::grid::object<
	int,
	2
> int2d_grid;

typedef fcppt::container::grid::object<
	int,
	3
> int3d_grid;
}

int main()
{
	int1d_grid one_dimensional(
		int1d_grid::dim(3));

	one_dimensional[int1d_grid::pos(0)] = 0;
	one_dimensional[int1d_grid::pos(1)] = 1;
	one_dimensional[int1d_grid::pos(2)] = 2;

	// Outputs 0, 1, 2
	for(int1d_grid::const_iterator it = one_dimensional.begin(); it != one_dimensional.end(); ++it)
		fcppt::io::cout() << it << FCPPT_TEXT("\n");

	int2d_grid two_dimensional(
		int2d_grid::dim(3,2));

	two_dimensional[int2d_grid::pos(0,0)] = 0;
	two_dimensional[int2d_grid::pos(1,0)] = 1;
	two_dimensional[int2d_grid::pos(2,0)] = 2;
	two_dimensional[int2d_grid::pos(0,1)] = 3;
	two_dimensional[int2d_grid::pos(1,1)] = 4;
	two_dimensional[int2d_grid::pos(2,1)] = 5;

	// Outputs 0, 1, 2, 3, 4, 5
	for(int2d_grid::const_iterator it = two_dimensional.begin(); it != two_dimensional.end(); ++it)
		fcppt::io::cout() << it << FCPPT_TEXT("\n");

	int3d_grid three_dimensional(
		int3d_grid::dim(3,2,2));

	// First slice
	three_dimensional[int3d_grid::pos(0,0,0)] = 0;
	three_dimensional[int3d_grid::pos(1,0,0)] = 1;
	three_dimensional[int3d_grid::pos(2,0,0)] = 2;
	three_dimensional[int3d_grid::pos(0,1,0)] = 3;
	three_dimensional[int3d_grid::pos(1,1,0)] = 4;
	three_dimensional[int3d_grid::pos(2,1,0)] = 5;
	// Second slice
	three_dimensional[int3d_grid::pos(0,0,1)] = 6;
	three_dimensional[int3d_grid::pos(1,0,1)] = 7;
	three_dimensional[int3d_grid::pos(2,0,1)] = 8;
	three_dimensional[int3d_grid::pos(0,1,1)] = 9;
	three_dimensional[int3d_grid::pos(1,1,1)] = 10;
	three_dimensional[int3d_grid::pos(2,1,1)] = 11;

	// Outputs 0, 1, 2, 3, 4, 5, 6, ..., 11
	for(int3d_grid::const_iterator it = three_dimensional.begin(); it != three_dimensional.end(); ++it)
		fcppt::io::cout() << it << FCPPT_TEXT("\n");
}
//! [grid_iteration]

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


//! [grid_iteration]
namespace
{

typedef
fcppt::container::grid::object<
	int,
	1
>
int1d_grid;

typedef
fcppt::container::grid::object<
	int,
	2
>
int2d_grid;

}

int
main()
{
	int1d_grid one_dimensional(
		int1d_grid::dim(3),
		fcppt::no_init{}
	);

	one_dimensional[int1d_grid::pos(0)] = 0;
	one_dimensional[int1d_grid::pos(1)] = 1;
	one_dimensional[int1d_grid::pos(2)] = 2;

	// Outputs 0, 1, 2
	for(
		auto const &elem
		:
		one_dimensional
	)
		fcppt::io::cout() << elem << FCPPT_TEXT(' ');

	fcppt::io::cout() << FCPPT_TEXT('\n');

	int2d_grid two_dimensional(
		int2d_grid::dim(3,2),
		fcppt::no_init{}
	);

	two_dimensional[int2d_grid::pos(0,0)] = 0;
	two_dimensional[int2d_grid::pos(1,0)] = 1;
	two_dimensional[int2d_grid::pos(2,0)] = 2;
	two_dimensional[int2d_grid::pos(0,1)] = 3;
	two_dimensional[int2d_grid::pos(1,1)] = 4;
	two_dimensional[int2d_grid::pos(2,1)] = 5;

	// Outputs 0, 1, 2, 3, 4, 5
	for(
		auto const &elem
		:
		two_dimensional
	)
		fcppt::io::cout() << elem << FCPPT_TEXT(' ');

	fcppt::io::cout() << FCPPT_TEXT('\n');
}
//! [grid_iteration]

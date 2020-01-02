//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>


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
		int1d_grid::dim(3u),
		0
	);

	one_dimensional.get_unsafe(int1d_grid::pos(0u)) = 0;
	one_dimensional.get_unsafe(int1d_grid::pos(1u)) = 1;
	one_dimensional.get_unsafe(int1d_grid::pos(2u)) = 2;

	// Outputs 0, 1, 2
	for(
		auto const &elem
		:
		one_dimensional
	)
		fcppt::io::cout() << elem << FCPPT_TEXT(' ');

	fcppt::io::cout() << FCPPT_TEXT('\n');

	int2d_grid two_dimensional(
		int2d_grid::dim(3u,2u),
		0
	);

	two_dimensional.get_unsafe(int2d_grid::pos(0u,0u)) = 0;
	two_dimensional.get_unsafe(int2d_grid::pos(1u,0u)) = 1;
	two_dimensional.get_unsafe(int2d_grid::pos(2u,0u)) = 2;
	two_dimensional.get_unsafe(int2d_grid::pos(0u,1u)) = 3;
	two_dimensional.get_unsafe(int2d_grid::pos(1u,1u)) = 4;
	two_dimensional.get_unsafe(int2d_grid::pos(2u,1u)) = 5;

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

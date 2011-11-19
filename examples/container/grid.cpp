//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [grid_simple]

#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/interpolate.hpp>
#include <fcppt/math/interpolation/linear_functor.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <iostream>

namespace
{
// typedef a three dimensional grid of ints
typedef fcppt::container::grid::object<
	int,
	3
> int3d_grid;

void
use_grid()
{
	// Create a 5 by 10 by 20 grid.
	// The initial values will be unspecified.
	int3d_grid grid(
		int3d_grid::dim(
			5u,
			10u,
			20u
		)
	);

	// Set the value on position (1,2,3) to 42
	grid[
		int3d_grid::dim(
			1u,
			2u,
			3u
		)
	] = 42;

	fcppt::io::cout()
		<< grid[
			int3d_grid::dim(
				1u,
				2u,
				3u
			)
		]
		<< FCPPT_TEXT('\n');
}

}
//! [grid_simple]

//! [grid_resize]
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/resize_preserve_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/core/reference.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2d_grid;

void
resize_grid()
{
	int2d_grid grid(
		int2d_grid::dim(
			2u,
			3u
		)
	);

	{
		int count = 0;

		// Initialize the grid with numbers from 0 to 5.
		// Note, that a grid will always be laid out in memory such that
		// the lower dimensions are closer together.
		std::generate(
			grid.begin(),
			grid.end(),
			boost::phoenix::ref(
				count
			)++
		);
	}

	fcppt::io::cout()
		<< grid
		<< FCPPT_TEXT('\n');

	// Give the grid one more row and column and initialize those with 42.
	fcppt::container::grid::resize_preserve_init(
		grid,
		int2d_grid::dim(
			3u,
			4u
		),
		42
	);

	fcppt::io::cout()
		<< grid
		<< FCPPT_TEXT('\n');
}

}
//! [grid_resize]

namespace
{
//! [grid_interpolate]
typedef fcppt::container::grid::object<
	float,
	2
> float2d_grid;

typedef fcppt::math::vector::static_<float,2>::type float2d_vector;

void
interpolate_grid()
{
	float2d_grid grid(
		float2d_grid::dim(
			2u,
			2u
		)
	);

	grid[float2d_grid::dim( 0u, 0u)] = 0.0f;
	grid[float2d_grid::dim( 0u, 1u)] = 1.0f;
	grid[float2d_grid::dim( 1u, 0u)] = 2.0f;
	grid[float2d_grid::dim( 1u, 1u)] = 3.0f;

	float const result =
		fcppt::container::grid::interpolate(
			grid,
			float2d_vector(0.5f,0.5f),
			fcppt::math::interpolation::linear_functor());

	// Will bilinearly interpolate ALL the grid points and return something
	// inbetween (too lazy to calculate)
	std::cout << result;
}
//! [grid_interpolate]
}

int main()
{
	use_grid();

	resize_grid();
}

//! [grid_iteration]

#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <iostream>

namespace
{
typedef fcppt::container::grid::object<
	int,
	1
> int1d_grid;

typedef fcppt::container::grid::object<
	int,
	2
> int1d_grid;

typedef fcppt::container::grid::object<
	int,
	3
> int1d_grid;
}

int main()
{
	int1d_grid one_dimensional(
		int1d_grid::dim(3));

	one_dimensional[int1d_grid(0)] = 0;
	one_dimensional[int1d_grid(1)] = 1;
	one_dimensional[int1d_grid(2)] = 2;

	// Outputs 0, 1, 2
	for(int1d_grid::const_iterator it = one_dimensional.begin(); it != one_dimensional.end(); ++it)0
		fcppt::io::cout() << it << FCPPT_TEXT("\n");

	int2d_grid two_dimensional(
		int2d_grid::dim(3,2));

	two_dimensional[int2d_grid(0,0)] = 0;
	two_dimensional[int2d_grid(1,0)] = 1;
	two_dimensional[int2d_grid(2,0)] = 2;
	two_dimensional[int2d_grid(0,1)] = 3;
	two_dimensional[int2d_grid(1,1)] = 4;
	two_dimensional[int2d_grid(2,1)] = 5;

	// Outputs 0, 1, 2, 3, 4, 5
	for(int2d_grid::const_iterator it = two_dimensional.begin(); it != two_dimensional.end(); ++it)0
		fcppt::io::cout() << it << FCPPT_TEXT("\n");

	int3d_grid three_dimensional(
		int3d_grid::dim(3,2,2));

	// First slice
	three_dimensional[int3d_grid(0,0,0)] = 0;
	three_dimensional[int3d_grid(1,0,0)] = 1;
	three_dimensional[int3d_grid(2,0,0)] = 2;
	three_dimensional[int3d_grid(0,1,0)] = 3;
	three_dimensional[int3d_grid(1,1,0)] = 4;
	three_dimensional[int3d_grid(2,1,0)] = 5;
	// Second slice
	three_dimensional[int3d_grid(0,0,1)] = 6;
	three_dimensional[int3d_grid(1,0,1)] = 7;
	three_dimensional[int3d_grid(2,0,1)] = 8;
	three_dimensional[int3d_grid(0,1,1)] = 9;
	three_dimensional[int3d_grid(1,1,1)] = 10;
	three_dimensional[int3d_grid(2,1,1)] = 11;

	// Outputs 0, 1, 2, 3, 4, 5, 6, ..., 11
	for(int3d_grid::const_iterator it = three_dimensional.begin(); it != three_dimensional.end(); ++it)0
		fcppt::io::cout() << it << FCPPT_TEXT("\n");
}
//! [grid_iteration]

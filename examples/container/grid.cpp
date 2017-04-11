//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/cast/int_to_float.hpp>
#include <fcppt/container/grid/interpolate.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/resize.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/interpolation/linear.hpp>


namespace
{

//! [grid_simple]
// typedef a three dimensional grid of ints
typedef
fcppt::container::grid::object<
	int,
	3
>
int3d_grid;

void
use_grid()
{
	// Create a 5 by 10 by 20 grid.
	int3d_grid grid(
		int3d_grid::dim(
			5u,
			10u,
			20u
		),
		0
	);

	// Set the value on position (1,2,3) to 42
	grid[
		int3d_grid::pos(
			1u,
			2u,
			3u
		)
	] = 42;

	fcppt::io::cout()
		<< grid[
			int3d_grid::pos(
				1u,
				2u,
				3u
			)
		]
		<< FCPPT_TEXT('\n');
}
//! [grid_simple]

}

namespace
{

void
init()
{
//! [grid_init]
	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2d_grid;

	// Initialize all cells to 42
	int2d_grid const all_42(
		int2d_grid::dim(
			3u,
			2u
		),
		42
	);

	// Initialize using a function
	int2d_grid const init_function(
		int2d_grid::dim(
			3u,
			2u
		),
		[](
			int2d_grid::pos const _pos
		)
		{
			return
				_pos.x()
				==
				_pos.y()
				?
					1
				:
					0
				;
		}
	);
//! [grid_init]
}

}

//! [grid_resize]
namespace
{

typedef fcppt::container::grid::object<
	int,
	2
> int2d_grid;

void
resize_grid()
{
	int2d_grid const grid(
		int2d_grid::dim(
			2u,
			3u
		),
		// Initialize the grid with numbers 0 to 5
		[](
			int2d_grid::pos
		)
		{
			static int count{
				0
			};

			return
				count++;
		}
	);

	fcppt::io::cout()
		<< grid
		<< FCPPT_TEXT('\n');

	int2d_grid const new_grid(
		// Give the grid one more row and column and initialize those with 42.
		fcppt::container::grid::resize(
			grid,
			int2d_grid::dim(
				3u,
				4u
			),
			[](
				int2d_grid::pos
			)
			{
				return
					42;
			}
		)
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
typedef
fcppt::container::grid::object<
	float,
	2
>
float2d_grid;

typedef
fcppt::math::vector::static_<
	float,
	2
>
float2d_vector;

void
interpolate_grid()
{
	float2d_grid const grid(
		float2d_grid::dim(
			2u,
			2u
		),
		[](
			float2d_grid::pos
		)
		{
			static int value{
				0
			};

			return
				fcppt::cast::int_to_float<
					float
				>(
					value++
				);
		}
	);

	float const result{
		fcppt::container::grid::interpolate(
			grid,
			float2d_vector{
				0.5f,
				0.5f
			},
			[](
				auto const _f,
				auto const _v1,
				auto const _v2
			)
			{
				return
					fcppt::math::interpolation::linear(
						_f,
						_v1,
						_v2
					);
			}
		)
	};

	// Will bilinearly interpolate ALL the grid points and return something
	// inbetween (too lazy to calculate)
	fcppt::io::cout()
		<< result
		<< FCPPT_TEXT('\n');
}
//! [grid_interpolate]
}

int
main()
{
	init();

	use_grid();

	resize_grid();

	interpolate_grid();
}

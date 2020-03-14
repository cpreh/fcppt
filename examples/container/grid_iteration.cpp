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

using
int1d_grid
=
fcppt::container::grid::object<
	int,
	1
>;

using
int2d_grid
=
fcppt::container::grid::object<
	int,
	2
>;

}

int
main()
{
	int1d_grid one_dimensional(
		int1d_grid::dim(3U), // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	one_dimensional.get_unsafe(int1d_grid::pos(0U)) = 0; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	one_dimensional.get_unsafe(int1d_grid::pos(1U)) = 1; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	one_dimensional.get_unsafe(int1d_grid::pos(2U)) = 2; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	// Outputs 0, 1, 2
	for(
		auto const &elem
		:
		one_dimensional
	)
	{
		fcppt::io::cout() << elem << FCPPT_TEXT(' ');
	}

	fcppt::io::cout() << FCPPT_TEXT('\n');

	int2d_grid two_dimensional(
		int2d_grid::dim(3U,2U), // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		0
	);

	two_dimensional.get_unsafe(int2d_grid::pos(0U,0U)) = 0; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	two_dimensional.get_unsafe(int2d_grid::pos(1U,0U)) = 1; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	two_dimensional.get_unsafe(int2d_grid::pos(2U,0U)) = 2; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	two_dimensional.get_unsafe(int2d_grid::pos(0U,1U)) = 3; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	two_dimensional.get_unsafe(int2d_grid::pos(1U,1U)) = 4; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	two_dimensional.get_unsafe(int2d_grid::pos(2U,1U)) = 5; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	// Outputs 0, 1, 2, 3, 4, 5
	for(
		auto const &elem
		:
		two_dimensional
	)
	{
		fcppt::io::cout() << elem << FCPPT_TEXT(' ');
	}

	fcppt::io::cout() << FCPPT_TEXT('\n');
}
//! [grid_iteration]

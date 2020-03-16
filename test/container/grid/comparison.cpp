//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/comparison.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid comparison"
	"[container],[grid]"
)
{
	using
	int2_grid
	=
	fcppt::container::grid::object<
		int,
		2
	>;

	int2_grid const test1(
		int2_grid::dim(
			5U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			10U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		),
		0
	);

	int2_grid test2(
		int2_grid::dim(
			10U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			2U
		),
		0
	);

	CHECK(
		test1
		!=
		test2
	);

	CHECK(
		test1
		<
		test2
	);

	CHECK(
		test1
		<=
		test2
	);

	CHECK_FALSE(
		test1
		>
		test2
	);

	CHECK_FALSE(
		test1
		>=
		test2
	);

	test2 = test1;

	CHECK(
		test1
		==
		test2
	);
}

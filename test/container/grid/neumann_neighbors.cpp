//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains.hpp>
#include <fcppt/container/grid/neumann_neighbor_array.hpp>
#include <fcppt/container/grid/neumann_neighbors.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::grid::pos<
	unsigned,
	2
>
pos;

typedef
fcppt::container::grid::neumann_neighbor_array<
	pos
>
array;

bool
contains_element(
	array const &_result,
	pos const _pos
)
{
	return
		fcppt::algorithm::contains(
			_result,
			_pos
		);
}

}

TEST_CASE(
	"container::grid::neumann_neighbors",
	"[container],[grid]"
)
{
	array const result(
		fcppt::container::grid::neumann_neighbors(
			pos(
				5u,
				7u
			)
		)
	);

	CHECK(
		contains_element(
			result,
			pos(
				4u,
				7u
			)
		)
	);

	CHECK(
		contains_element(
			result,
			pos(
				6u,
				7u
			)
		)
	);

	CHECK(
		contains_element(
			result,
			pos(
				5u,
				6u
			)
		)
	);

	CHECK(
		contains_element(
			result,
			pos(
				5u,
				8u
			)
		)
	);
}

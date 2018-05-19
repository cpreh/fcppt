//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid pos range",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::pos<
		unsigned,
		2
	>
	pos;

	typedef
	fcppt::container::grid::min_from_pos<
		pos
	>
	min;

	typedef
	fcppt::container::grid::sup_from_pos<
		pos
	>
	sup;

	CHECK(
		fcppt::container::grid::make_pos_range_start_end(
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				pos(
					3u,
					2u
				)
			}
		).size()
		==
		6u
	);

	CHECK(
		fcppt::container::grid::make_pos_range_start_end(
			min{
				pos(
					3u,
					2u
				)
			},
			sup{
				pos(
					3u,
					1u
				)
			}
		).size()
		==
		0u
	);
}

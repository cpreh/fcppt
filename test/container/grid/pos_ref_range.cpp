//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/use.hpp>
#include <fcppt/container/grid/make_pos_ref_crange.hpp>
#include <fcppt/container/grid/make_pos_ref_crange_start_end.hpp>
#include <fcppt/container/grid/make_pos_ref_range.hpp>
#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid: pos refrange",
	"[container],[grid]"
)
{
	using
	element_type
	=
	fcppt::container::grid::pos<
		std::size_t,
		2
	>;

	using
	dim2_grid
	=
	fcppt::container::grid::object<
		element_type,
		2
	>;

	using
	min
	=
	fcppt::container::grid::min_from_pos<
		dim2_grid::pos
	>;

	using
	sup
	=
	fcppt::container::grid::sup_from_pos<
		dim2_grid::pos
	>;

	using
	pos
	=
	dim2_grid::pos;

	dim2_grid grid(
		dim2_grid::dim(
			4U,
			6U
		),
		fcppt::math::vector::null<
			pos
		>()
	);

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range(
			grid
		)
	)
	{
		element.value()
		=
		element.pos();
	}

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_crange(
			grid
		)
	)
	{
		CHECK(
			element.value()
			==
			element.pos()
		);
	}

	grid =
		dim2_grid(
			dim2_grid::dim(
				4U,
				6U
			),
			fcppt::math::vector::null<
				element_type
			>()
		);

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos(
					1U,
					1U
				)
			},
			sup{
				pos(
					3U,
					3U
				)
			}
		)
	)
	{
		element.value()
		=
		element.pos();
	}

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_crange_start_end(
			grid,
			min{
				pos(
					1U,
					1U
				)
			},
			sup{
				pos(
					3U,
					3U
				)
			}
		)
	)
	{
		CHECK(
			element.value()
			==
			element.pos()
		);
	}

	bool loop_empty(
		true
	);

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				fcppt::math::vector::null<
					pos
				>()
			}
		)
	)
	{
		FCPPT_USE(
			element
		);

		loop_empty =
			false;
	}

	CHECK(
		loop_empty
	);

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				pos(
					0U,
					1U
				)
			}
		)
	)
	{
		FCPPT_USE(
			element
		);

		loop_empty =
			false;
	}

	CHECK(
		loop_empty
	);

	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				pos(
					1U,
					0U
				)
			}
		)
	)
	{
		FCPPT_USE(
			element
		);

		loop_empty =
			false;
	}

	CHECK(
		loop_empty
	);
}

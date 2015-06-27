//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/make_pos_ref_crange.hpp>
#include <fcppt/container/grid/make_pos_ref_crange_start_end.hpp>
#include <fcppt/container/grid/make_pos_ref_range.hpp>
#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/min_from_object.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_object.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_pos_ref_range
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::pos<
		std::size_t,
		2
	>
	dim;

	typedef
	fcppt::container::grid::object<
		dim,
		2
	>
	dim2_grid;

	typedef
	fcppt::container::grid::min_from_object<
		dim2_grid
	>
	min;

	typedef
	fcppt::container::grid::sup_from_object<
		dim2_grid
	>
	sup;

	typedef
	dim2_grid::pos
	pos;

	dim2_grid grid(
		dim2_grid::dim(
			4,
			6
		)
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range(
			grid
		)
	)
		element.value()
		=
		element.pos();

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_crange(
			grid
		)
	)
		BOOST_CHECK(
			element.value()
			==
			element.pos()
		);

	grid =
		dim2_grid(
			dim2_grid::dim(
				4,
				6
			)
		);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos(
					1,
					1
				)
			},
			sup{
				pos(
					3,
					3
				)
			}
		)
	)
		element.value()
		=
		element.pos();

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_crange_start_end(
			grid,
			min{
				pos(
					1,
					1
				)
			},
			sup{
				pos(
					3,
					3
				)
			}
		)
	)
		BOOST_CHECK(
			element.value()
			==
			element.pos()
		);


	bool loop_empty(
		true
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos::null()
			},
			sup{
				pos::null()
			}
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos::null()
			},
			sup{
				pos(
					0,
					1
				)
			}
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos::null()
			},
			sup{
				pos(
					1,
					0
				)
			}
		)
	)
		loop_empty = false;

	BOOST_CHECK(
		loop_empty
	);
}

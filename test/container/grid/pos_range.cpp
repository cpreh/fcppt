//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_pos_range
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::make_pos_range_start_end(
			min{
				pos::null()
			},
			sup{
				pos(
					3u,
					2u
				)
			}
		).size(),
		6u
	);

	BOOST_CHECK_EQUAL(
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
		).size(),
		0u
	);

}

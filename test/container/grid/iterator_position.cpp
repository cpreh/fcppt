//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/container/grid/iterator_position.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_iterator_position
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	typedef
	int2_grid::pos
	pos;

	int2_grid const grid(
		int2_grid::dim(
			2u,
			2u
		),
		fcppt::no_init{}
	);

	int2_grid::const_iterator it{
		grid.begin()
	};

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::iterator_position(
			grid,
			it++
		),
		pos(
			0u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::iterator_position(
			grid,
			it++
		),
		pos(
			1u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::iterator_position(
			grid,
			it++
		),
		pos(
			0u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::iterator_position(
			grid,
			it++
		),
		pos(
			1u,
			1u
		)
	);
}

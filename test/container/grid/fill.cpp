//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/container/grid/fill.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <numeric>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_fill
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	int2_grid test(
		int2_grid::dim(
			2u,
			2u
		),
		fcppt::no_init{}
	);

	typedef
	int2_grid::pos
	pos;

	fcppt::container::grid::fill(
		test,
		[](
			pos const _pos
		)
		{
			return
				std::accumulate(
					_pos.begin(),
					_pos.end(),
					0
				);
		}
	);

	BOOST_CHECK_EQUAL(
		test[
			pos(
				0u,
				0u
			)
		],
		0
	);

	BOOST_CHECK_EQUAL(
		test[
			pos(
				1u,
				0u
			)
		],
		1
	);

	BOOST_CHECK_EQUAL(
		test[
			pos(
				0u,
				1u
			)
		],
		1
	);

	BOOST_CHECK_EQUAL(
		test[
			pos(
				1u,
				1u
			)
		],
		2
	);
}

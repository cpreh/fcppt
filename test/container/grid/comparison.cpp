//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/comparison.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_compare
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		int,
		2
	>
	int2_grid;

	int2_grid const test1(
		int2_grid::dim(
			5u,
			10u
		),
		0
	);

	int2_grid test2(
		int2_grid::dim(
			10u,
			2u
		),
		0
	);

	BOOST_CHECK(
		test1 != test2
	);

	BOOST_CHECK(
		test1 < test2
	);

	BOOST_CHECK(
		test1 <= test2
	);

	BOOST_CHECK(
		!(test1 > test2)
	);

	BOOST_CHECK(
		!(test1 >= test2)
	);

	test2 = test1;

	BOOST_CHECK(
		test1 == test2
	);
}

//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/fill.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
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
		0
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
				fcppt::cast::size<
					int
				>(
					fcppt::cast::to_signed(
						fcppt::algorithm::fold(
							_pos.storage(),
							fcppt::literal<
								pos::value_type
							>(
								0
							),
							std::plus<
								pos::value_type
							>()
						)
					)
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

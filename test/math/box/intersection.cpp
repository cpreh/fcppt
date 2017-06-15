//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/intersection.hpp>
#include <fcppt/math/box/null.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_box_intersection
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::box::object<
		int,
		2
	> box_i2;

	box_i2 const
		box1(
			box_i2::vector(
				1,
				1
			),
			box_i2::dim(
				2,
				2
			)
		),
		box2(
			box_i2::vector(
				0,
				0
			),
			box_i2::dim(
				4,
				4
			)
		),
		box3(
			box_i2::vector(
				2,
				2
			),
			box_i2::dim(
				2,
				2
			)
		),
		box4(
			box_i2::vector(
				5,
				5
			),
			box_i2::dim(
				1,
				1
			)
		),
		intersection1(
			fcppt::math::box::intersection(
				box1,
				box2
			)
		),
		intersection2(
			fcppt::math::box::intersection(
				box1,
				box3
			)
		),
		intersection3(
			fcppt::math::box::intersection(
				box1,
				box4
			)
		);

	BOOST_CHECK_EQUAL(
		intersection1,
		box1
	);

	box_i2 const result2(
		box_i2::vector(
			2,
			2
		),
		box_i2::dim(
			1,
			1
		)
	);

	BOOST_CHECK_EQUAL(
		intersection2,
		result2
	);

	BOOST_CHECK_EQUAL(
		intersection3,
		fcppt::math::box::null<
			box_i2
		>()
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/sphere/circle.hpp>
#include <fcppt/math/sphere/comparison.hpp>
#include <fcppt/math/sphere/intersects.hpp>
#include <fcppt/math/sphere/object_impl.hpp>
#include <fcppt/math/sphere/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	circle_intersects
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::sphere::circle<
		float
	>
	circle_type;

	BOOST_CHECK(
		fcppt::math::sphere::intersects(
			circle_type(
				circle_type::point_type(
					0.f,
					0.f
				),
				1.f
			),
			circle_type(
				circle_type::point_type(
					1.f,
					0.f
				),
				1.f
			)
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	circle_comparison
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::sphere::circle<
		int
	>
	circle_type;

	BOOST_CHECK_EQUAL(
		circle_type(
			circle_type::point_type(
				1,
				3
			),
			2
		),
		circle_type(
			circle_type::point_type(
				1,
				3
			),
			2
		)
	);
}

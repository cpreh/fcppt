//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_box_contains_point
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::box::rect<
		int
	>
	box2;

	box2 const outer{
		box2::vector{
			0,
			0
		},
		box2::dim{
			5,
			5
		}
	};

	BOOST_CHECK(
		fcppt::math::box::contains_point(
			outer,
			box2::vector{
				1,
				1
			}
		)
	);

	BOOST_CHECK(
		!fcppt::math::box::contains_point(
			outer,
			box2::vector{
				-1,
				1
			}
		)
	);

	BOOST_CHECK(
		!fcppt::math::box::contains_point(
			outer,
			box2::vector{
				6,
				5
			}
		)
	);
}

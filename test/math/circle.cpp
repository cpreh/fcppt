//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/circle/circle.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(circle_intersects)
{
	typedef fcppt::math::circle::basic<
		float,
		2
	> circle_type;

	BOOST_CHECK(
		fcppt::math::circle::intersects(
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

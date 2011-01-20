//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_power_of_2.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	is_power_of_2
)
{
	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			0u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			1u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			2u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			4u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			3u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			5u
		)
	);
}

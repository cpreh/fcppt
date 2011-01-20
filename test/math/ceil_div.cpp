//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/ceil_div.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	ceil_div
)
{
	BOOST_CHECK(
		fcppt::math::ceil_div(
			0u,
			1u
		)
		== 0u
	);

	BOOST_CHECK(
		fcppt::math::ceil_div(
			1u,
			1u
		)
		== 1u
	);

	BOOST_CHECK(
		fcppt::math::ceil_div(
			5u,
			3u
		)
		== 2u
	);

	BOOST_CHECK(
		fcppt::math::ceil_div(
			6u,
			3u
		)
		== 2u
	);
}

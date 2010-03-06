//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/almost_zero.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/is_negative.hpp>
#include <fcppt/math/is_power_of_2.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(math_almost_zero)
{
	BOOST_CHECK(
		fcppt::math::almost_zero(
			0
		)
	);

	BOOST_CHECK(
		fcppt::math::almost_zero(
			0.0
		)
	);
}

BOOST_AUTO_TEST_CASE(math_diff)
{
	BOOST_CHECK(
		fcppt::math::diff(
			10u,
			20u
		)
		== 10u
	);

	BOOST_CHECK(
		fcppt::math::diff(
			-1,
			1
		)
		== 2
	);
}

BOOST_AUTO_TEST_CASE(math_is_negative)
{
	BOOST_CHECK(
		fcppt::math::is_negative(
			-10
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_negative(
			10.f
		)
	);
}

BOOST_AUTO_TEST_CASE(math_is_power_of_2)
{
	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			1024u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			0u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			3u
		)
	);
}

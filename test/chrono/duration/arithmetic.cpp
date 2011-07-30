//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/chrono.hpp>
#include <fcppt/ratio/milli.hpp>
#include <fcppt/math/compare.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	chrono_duration_arithmetic
)
{
	typedef fcppt::chrono::duration<
		float,
		fcppt::ratio::milli
	> float_millis;

	BOOST_REQUIRE(
		fcppt::math::compare(
			float_millis(2.f)
			/ float_millis(1.f),
			2.f/1.f
		)
	);
}

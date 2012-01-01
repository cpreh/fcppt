//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/duration.hpp>
#include <fcppt/ratio/milli.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	chrono_duration_arithmetic
)
{
	typedef fcppt::chrono::duration<
		float,
		fcppt::ratio::milli
	> float_millis;

	BOOST_REQUIRE(
		float_millis(2.f) / float_millis(1.f) - 2.f/1.f < std::numeric_limits<float>::epsilon());
}

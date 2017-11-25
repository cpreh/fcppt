//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/diff.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_diff
)
{
	BOOST_CHECK_EQUAL(
		fcppt::math::diff(
			10u,
			20u
		),
		10u
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::diff(
			-1,
			1
		),
		2
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_zero.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	is_zero
)
{
	BOOST_CHECK(
		fcppt::math::is_zero(
			0
		)
	);

	BOOST_CHECK(
		fcppt::math::is_zero(
			0.f
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_zero(
			1
		)
	);
}

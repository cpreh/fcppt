//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/chrono/chrono.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	chrono_duration_convert
)
{
	fcppt::chrono::nanoseconds const nano(
		1000u * 1000u * 1000u * 4u
	);

	fcppt::chrono::seconds const sec(
		fcppt::chrono::duration_cast<
			fcppt::chrono::seconds
		>(
			nano
		)
	);

	BOOST_REQUIRE(
		sec.count() == 4u
	);

	fcppt::chrono::nanoseconds convert_back(
		fcppt::chrono::duration_cast<
			fcppt::chrono::nanoseconds
		>(
			sec
		)
	);

	BOOST_REQUIRE(
		convert_back.count()
		== 1000u * 1000u * 1000u * 4u
	);

	convert_back -=
		fcppt::chrono::nanoseconds(
			1000u * 1000u * 1000u
		);

	BOOST_REQUIRE(
		convert_back.count()
		== 1000u * 1000u * 1000u * 3u
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::is_power_of_2",
	"[math]"
)
{
	CHECK_FALSE(
		fcppt::math::is_power_of_2(
			0u
		)
	);

	CHECK(
		fcppt::math::is_power_of_2(
			1u
		)
	);

	CHECK(
		fcppt::math::is_power_of_2(
			2u
		)
	);

	CHECK(
		fcppt::math::is_power_of_2(
			4u
		)
	);

	CHECK_FALSE(
		fcppt::math::is_power_of_2(
			3u
		)
	);

	CHECK_FALSE(
		fcppt::math::is_power_of_2(
			5u
		)
	);
}

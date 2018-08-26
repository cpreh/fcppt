//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_zero.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::is_zero",
	"[math]"
)
{
	CHECK(
		fcppt::math::is_zero(
			0
		)
	);

	CHECK(
		fcppt::math::is_zero(
			0.f
		)
	);

	CHECK_FALSE(
		fcppt::math::is_zero(
			1
		)
	);
}

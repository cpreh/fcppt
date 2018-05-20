//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/diff.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::diff",
	"[math]"
)
{
	CHECK(
		fcppt::math::diff(
			10u,
			20u
		)
		==
		10u
	);

	CHECK(
		fcppt::math::diff(
			-1,
			1
		)
		==
		2
	);
}

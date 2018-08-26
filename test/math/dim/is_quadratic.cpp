//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/is_quadratic.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim::is_quadratic",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	CHECK_FALSE(
		fcppt::math::dim::is_quadratic(
			ui2_dim{
				10u,
				20u
			}
		)
	);

	CHECK(
		fcppt::math::dim::is_quadratic(
			ui2_dim{
				10u,
				10u
			}
		)
	);
}

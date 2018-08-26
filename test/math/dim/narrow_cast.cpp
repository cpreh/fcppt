//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/narrow_cast.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim::narrow_cast",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	typedef
	fcppt::math::dim::static_<
		int,
		3
	>
	i3_dim;

	CHECK(
		i2_dim(
			1,
			2
		)
		==
		fcppt::math::dim::narrow_cast<
			i2_dim
		>(
			i3_dim(
				1,
				2,
				3
			)
		)
	);
}

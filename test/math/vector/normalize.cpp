//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::normalize",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		float,
		2
	>
	float2_vec;

	CHECK(
		fcppt::math::vector::normalize(
			float2_vec{
				2.f,
				0.f
			}
		).has_value()
	);

	CHECK_FALSE(
		fcppt::math::vector::normalize(
			float2_vec{
				0.f,
				0.f
			}
		).has_value()
	);
}

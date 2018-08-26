//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/distance.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::distance",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		float,
		2
	>
	float2_vector;

	CHECK_THAT(
		std::abs(
			fcppt::math::vector::distance(
				float2_vector(
					1.f,
					2.f
				),
				float2_vector(
					3.f,
					4.f
				)
			)
			-
			2.8f
		),
		Catch::Matchers::WithinAbs(
			0.f,
			0.1f
		)
	);

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uint2_vector;

	CHECK_THAT(
		std::abs(
			fcppt::math::vector::distance<
				float
			>(
				uint2_vector(
					1u,
					2u
				),
				uint2_vector(
					3u,
					4u
				)
			)
			-
			2.8f
		),
		Catch::Matchers::WithinAbs(
			0.f,
			0.1f
		)
	);
}

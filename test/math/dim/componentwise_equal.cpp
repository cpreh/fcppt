//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/componentwise_equal.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim::componentwise_equal",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		float,
		2
	>
	f2_dim;

	float const epsilon(
		0.00001f
	);

	CHECK(
		fcppt::math::dim::componentwise_equal(
			f2_dim(
				1.f,
				2.f
			),
			f2_dim(
				1.f,
				2.f
			),
			epsilon
		)
	);

	CHECK_FALSE(
		fcppt::math::dim::componentwise_equal(
			f2_dim(
				1.f,
				2.f
			),
			f2_dim(
				1.1f,
				2.f
			),
			epsilon
		)
	);
}

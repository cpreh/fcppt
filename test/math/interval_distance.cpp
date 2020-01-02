//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/interval_distance.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::interval_distance",
	"[math]"
)
{
	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				0,
				2
			),
			fcppt::make_homogenous_pair(
				3,
				10
			)
		)
		==
		1
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				3,
				10
			),
			fcppt::make_homogenous_pair(
				0,
				2
			)
		)
		==
		1
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				2,
				5
			),
			fcppt::make_homogenous_pair(
				4,
				7
			)
		)
		==
		-1
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				4,
				7
			),
			fcppt::make_homogenous_pair(
				2,
				5
			)
		)
		==
		-1
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				4,
				6
			),
			fcppt::make_homogenous_pair(
				6,
				7
			)
		)
		==
		0
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				6,
				7
			),
			fcppt::make_homogenous_pair(
				4,
				6
			)
		)
		==
		0
	);

	CHECK(
		fcppt::math::interval_distance(
			fcppt::make_homogenous_pair(
				3,
				4
			),
			fcppt::make_homogenous_pair(
				0,
				10
			)
		)
		==
		-3
	);
}

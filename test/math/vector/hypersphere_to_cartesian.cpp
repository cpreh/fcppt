//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/hypersphere_to_cartesian.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cmath>
#include <limits>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::hypersphere_to_cartesian",
	"[math],[vector]"
)
{
	typedef
	float
	real;

	real const epsilon{
		std::numeric_limits<
			real
		>::epsilon()
	};

	typedef
	fcppt::math::vector::static_<
		real,
		1
	>
	fvector1;

	typedef
	fcppt::math::vector::static_<
		real,
		2
	>
	fvector2;

	typedef
	fcppt::math::vector::static_<
		real,
		3
	>
	fvector3;

	real const
		phi1{
			fcppt::literal<
				real
			>(
				1.5
			)
		},
		phi2{
			fcppt::literal<
				real
			>(
				0.5
			)
		};

	CHECK(
		fcppt::math::vector::componentwise_equal(
			fcppt::math::vector::hypersphere_to_cartesian(
				fvector1{
					phi1
				}
			),
			fvector2{
				std::cos(
					phi1
				),
				std::sin(
					phi1
				)
			},
			epsilon
		)
	);

	CHECK(
		fcppt::math::vector::componentwise_equal(
			fcppt::math::vector::hypersphere_to_cartesian(
				fvector2{
					phi1,
					phi2
				}
			),
			fvector3(
				std::cos(
					phi1
				),
				std::sin(
					phi1
				) *
				std::cos(
					phi2
				),
				std::sin(
					phi1
				) *
				std::sin(
					phi2
				)
			),
			epsilon
		)
	);
}

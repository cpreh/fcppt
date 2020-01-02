//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe_multi.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
float
scalar;

bool
almost_equal(
	fcppt::optional::object<
		scalar
	> const _f1,
	fcppt::optional::object<
		scalar
	> const _f2
)
{
	return
		fcppt::optional::maybe_multi(
			fcppt::const_(
				false
			),
			[](
				scalar const _x1,
				scalar const _x2
			)
			{
				return
					fcppt::math::diff(
						_x1,
						_x2
					)
					<
					fcppt::literal<
						scalar
					>(
						0.01f
					);
			},
			_f1,
			_f2
		);
}

}

TEST_CASE(
	"math::vector::atan2",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		scalar,
		2
	>
	float2_vec;

	scalar const pi{
		fcppt::math::pi<
			scalar
		>()
	};

	CHECK_FALSE(
		fcppt::math::vector::atan2(
			float2_vec{
				0.f,
				0.f
			}
		).has_value()
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					1.f,
					0.f
				}
			),
			fcppt::optional::make(
				0.f
			)
		)
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					-1.f,
					0.f
				}
			),
			fcppt::optional::make(
				pi
			)
		)
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					0.f,
					1.f
				}
			),
			fcppt::optional::make(
				pi
				/
				2.f
			)
		)
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					0.f,
					-1.f
				}
			),
			fcppt::optional::make(
				-pi
				/
				2.f
			)
		)
	);
}

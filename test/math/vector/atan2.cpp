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
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

using
scalar
=
float;

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
		fcppt::optional::from(
			fcppt::optional::apply(
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
							0.01F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
						);
				},
				_f1,
				_f2
			),
			fcppt::const_(
				false
			)
		);
}

}

TEST_CASE(
	"math::vector::atan2",
	"[math],[vector]"
)
{
	using
	float2_vec
	=
	fcppt::math::vector::static_<
		scalar,
		2
	>;

	scalar const pi{
		fcppt::math::pi<
			scalar
		>()
	};

	CHECK_FALSE(
		fcppt::math::vector::atan2(
			float2_vec{
				0.F,
				0.F
			}
		).has_value()
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					1.F,
					0.F
				}
			),
			fcppt::optional::make(
				0.F
			)
		)
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					-1.F,
					0.F
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
					0.F,
					1.F
				}
			),
			fcppt::optional::make(
				pi
				/
				2.F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);

	CHECK(
		almost_equal(
			fcppt::math::vector::atan2(
				float2_vec{
					0.F,
					-1.F
				}
			),
			fcppt::optional::make(
				-pi
				/
				2.F // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);
}

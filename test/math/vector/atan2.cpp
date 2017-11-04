//          Copyright Carl Philipp Reh 2009 - 2017.
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
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_vector_atan2
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK(
		!fcppt::math::vector::atan2(
			float2_vec{
				0.f,
				0.f
			}
		).has_value()
	);

	BOOST_CHECK(
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

	BOOST_CHECK(
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

	BOOST_CHECK(
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

	BOOST_CHECK(
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

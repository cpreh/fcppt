//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/componentwise_equal.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_dim_componentwise_equal
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::dim::static_<
		float,
		2
	>
	f2_dim;

	float const epsilon(
		0.00001f
	);

	BOOST_CHECK(
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

	BOOST_CHECK(
		!fcppt::math::dim::componentwise_equal(
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

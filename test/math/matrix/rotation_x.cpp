//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/pi.hpp>
#include <fcppt/math/matrix/rotation_x.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_translation
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	> matrix_type;

	matrix_type const trans(
		fcppt::math::matrix::rotation_x(
			fcppt::math::pi<float>()
		)
	);

	typedef fcppt::math::vector::static_<
		float,
		4
	> vector_type;

	vector_type const vec(
		0.f,
		1.f,
		0.f,
		1.f
	);

	float const epsilon{
		0.001f
	};

	BOOST_CHECK((
		fcppt::math::vector::componentwise_equal(
			trans * vec,
			vector_type(
				0.f,
				-1.f,
				0.f,
				1.f
			),
			epsilon
		)
	));
}

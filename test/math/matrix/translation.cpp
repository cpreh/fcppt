//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(math_matrix_translation)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	>::type matrix_type;

	float const epsilon(
		std::numeric_limits<
			float
		>::epsilon()
	);

	matrix_type const trans(
		fcppt::math::matrix::translation(
			5.f,
			3.f,
			42.f
		)
	);

	BOOST_REQUIRE(
		fcppt::math::matrix::componentwise_equal(
			trans,
			matrix_type(
				1.f, 0.f, 0.f, 5.f,
				0.f, 1.f, 0.f, 3.f,
				0.f, 0.f, 1.f, 42.f,
				0.f, 0.f, 0.f, 1.f
			),
			epsilon
		)
	);

	typedef fcppt::math::vector::static_<
		float,
		4
	>::type vector_type;

	vector_type const vec(
		1.f,
		2.f,
		3.f,
		1.f
	);

	BOOST_REQUIRE(
		fcppt::math::vector::componentwise_equal(
			trans * vec,
			vector_type(
				6.f,
				5.f,
				45.f,
				1.f
			),
			epsilon
		)
	);
}

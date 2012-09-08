//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/multiply_matrix4_vector3.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(multiply)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::matrix::static_<
		int,
		3,
		3
	>::type mat3;

	mat3 const
		left(
			1,2,3,
			4,5,6,
			7,8,9
		),
		right(
			10,11,12,
			13,14,15,
			16,17,18
		),
		result(
			left * right
		);

	fcppt::io::cout()
		<< result
		<< FCPPT_TEXT('\n');

	BOOST_REQUIRE(
		result
		==
		mat3(
			84,90,96,
			201,216,231,
			318,342,366
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
BOOST_AUTO_TEST_CASE(multiply_matrix4_vector3)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::matrix::static_<
		int,
		4,
		4
	>::type mat4;

	typedef fcppt::math::vector::static_<
		int,
		3
	>::type vec3;

	mat4 const
		left(
			1,2,3,4,
			5,6,7,8,
			9,10,11,12,
			13,14,15,16
		);

	vec3 const
		right(
			1,
			2,
			3),
		result(
			fcppt::math::matrix::multiply_matrix4_vector3(
				left,
				right));

	fcppt::io::cout()
		<< result
		<< FCPPT_TEXT('\n');

	BOOST_REQUIRE(
		result
		==
		vec3(
			18,46,74
		)
	);
}

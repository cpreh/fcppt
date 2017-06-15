//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_multiply
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		3
	>
	mat3;

	mat3 const
		left(
			fcppt::math::matrix::row(
				1,2,3
			),
			fcppt::math::matrix::row(
				4,5,6
			),
			fcppt::math::matrix::row(
				7,8,9
			)
		),
		right(
			fcppt::math::matrix::row(
				10,11,12
			),
			fcppt::math::matrix::row(
				13,14,15
			),
			fcppt::math::matrix::row(
				16,17,18
			)
		),
		result(
			left * right
		);

	fcppt::io::cout()
		<< result
		<< FCPPT_TEXT('\n');

	BOOST_CHECK_EQUAL(
		result,
		mat3(
			fcppt::math::matrix::row(
				84,90,96
			),
			fcppt::math::matrix::row(
				201,216,231
			),
			fcppt::math::matrix::row(
				318,342,366
			)
		)
	);
}

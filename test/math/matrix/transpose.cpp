//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/transpose.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_transpose
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		3
	>
	matrix_type;

	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		2
	>
	transposed_matrix_type;

	transposed_matrix_type const transposed(
		fcppt::math::matrix::transpose(
			matrix_type(
				fcppt::math::matrix::row(
					1, 2, 3
				),
				fcppt::math::matrix::row(
					4, 5, 6
				)
			)
		)
	);

	BOOST_CHECK_EQUAL(
		transposed,
		transposed_matrix_type(
			fcppt::math::matrix::row(
				1, 4
			),
			fcppt::math::matrix::row(
				2, 5
			),
			fcppt::math::matrix::row(
				3, 6
			)
		)
	);
}

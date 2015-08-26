//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::math::matrix::static_<
	int,
	2,
	2
>
matrix_type;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_operators_add
)
{
FCPPT_PP_POP_WARNING

	matrix_type const first(
		fcppt::math::matrix::row(
			1, 2
		),
		fcppt::math::matrix::row(
			3, 4
		)
	);

	matrix_type second(
		fcppt::math::matrix::row(
			2, 3
		),
		fcppt::math::matrix::row(
			4, 5
		)
	);

	second += first;

	BOOST_CHECK_EQUAL(
		second,
		matrix_type(
			fcppt::math::matrix::row(
				3, 5
			),
			fcppt::math::matrix::row(
				7, 9
			)
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_operators_scalar
)
{
FCPPT_PP_POP_WARNING

	matrix_type first(
		fcppt::math::matrix::row(
			1, 2
		),
		fcppt::math::matrix::row(
			3, 4
		)
	);

	first *= 3;

	BOOST_CHECK_EQUAL(
		first,
		matrix_type(
			fcppt::math::matrix::row(
				3, 6
			),
			fcppt::math::matrix::row(
				9, 12
			)
		)
	);
}

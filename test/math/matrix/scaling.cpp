//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
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
	math_matrix_scaling
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		int,
		4,
		4
	>
	matrix_type;

	matrix_type const trans(
		fcppt::math::matrix::scaling(
			5,
			3,
			4
		)
	);

	BOOST_CHECK_EQUAL(
		trans,
		matrix_type(
			fcppt::math::matrix::row(
				5, 0, 0, 0
			),
			fcppt::math::matrix::row(
				0, 3, 0, 0
			),
			fcppt::math::matrix::row(
				0, 0, 4, 0
			),
			fcppt::math::matrix::row(
				0, 0, 0, 1
			)
		)
	);

	typedef
	fcppt::math::vector::static_<
		int,
		4
	>
	vector_type;

	vector_type const vec(
		1,
		2,
		3,
		1
	);

	BOOST_CHECK_EQUAL(
		trans
		*
		vec,
		vector_type(
			5,
			6,
			12,
			1
		)
	);

}

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/object.hpp>
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
	math_matrix_access
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	matrix_type;

	matrix_type const mat(
		fcppt::math::matrix::row(
			-3, 2
		),
		fcppt::math::matrix::row(
			-1, 0
		)
	);

	BOOST_CHECK_EQUAL(
		mat[0][0],
		-3
	);

	BOOST_CHECK_EQUAL(
		mat[0][1],
		2
	);

	BOOST_CHECK_EQUAL(
		mat[1][0],
		-1
	);

	BOOST_CHECK_EQUAL(
		mat[1][1],
		0
	);
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/at_c.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
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
	math_matrix_view
)
{
FCPPT_PP_POP_WARNING

	typedef int value_type;

	constexpr std::size_t const size = 3;

	typedef
	fcppt::math::matrix::static_<
		value_type,
		size,
		size
	>
	matrix_type;

	typedef
	fcppt::math::vector::static_<
		value_type,
		size
	>
	vector_type;

	matrix_type const matrix(
		fcppt::math::matrix::row(
			-3, 2, -5
		),
		fcppt::math::matrix::row(
			-1, 0, -2
		),
		fcppt::math::matrix::row(
			3, -4, 1
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::matrix::at_c<
			0
		>(
			matrix
		),
		vector_type(
			-3,
			2,
			-5
		)
	);

	vector_type vec(
		fcppt::math::matrix::at_c<
			0
		>(
			matrix
		)
	);

	vec =
		fcppt::math::matrix::at_c<
			1
		>(
			matrix
		);

	BOOST_CHECK_EQUAL(
		vec,
		vector_type(
			-1,
			0,
			-2
		)
	);
}

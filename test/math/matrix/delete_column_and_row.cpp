//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(delete_row_and_column)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		float,
		3,
		4
	>
	large_matrix_type;

	typedef
	fcppt::math::matrix::static_<
		float,
		2,
		3
	>
	small_matrix_type;

	large_matrix_type const t(
		1.f, 2.f, 3.f,
		4.f, 5.f, 6.f,
		7.f, 8.f, 9.f,
		10.f,11.f,12.f
	);

	float const epsilon(
		std::numeric_limits<
			float
		>::epsilon()
	);

	BOOST_CHECK((
		fcppt::math::matrix::componentwise_equal(
			fcppt::math::matrix::delete_row_and_column(
				t,
				fcppt::literal<
					large_matrix_type::size_type
				>(
					2
				),
				fcppt::literal<
					large_matrix_type::size_type
				>(
					1
				)
			),
			small_matrix_type(
				1.f, 3.f,
				4.f, 6.f,
				10.f, 12.f
			),
			epsilon
		)
	));

	BOOST_CHECK((
		fcppt::math::matrix::componentwise_equal(
			fcppt::math::matrix::delete_row_and_column(
				t,
				fcppt::literal<
					large_matrix_type::size_type
				>(
					0
				),
				fcppt::literal<
					large_matrix_type::size_type
				>(
					0
				)
			),
			small_matrix_type(
				5.f, 6.f,
				8.f, 9.f,
				11.f, 12.f
			),
			epsilon
		)
	));
}

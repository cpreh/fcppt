//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_delete_row_and_column
)
{
	typedef
	fcppt::math::matrix::static_<
		int,
		4,
		3
	>
	large_matrix_type;

	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		2
	>
	small_matrix_type;

	large_matrix_type const t(
		fcppt::math::matrix::row(
			1, 2, 3
		),
		fcppt::math::matrix::row(
			4, 5, 6
		),
		fcppt::math::matrix::row(
			7, 8, 9
		),
		fcppt::math::matrix::row(
			10, 11, 12
		)
	);

	{
		small_matrix_type const result{
			fcppt::math::matrix::delete_row_and_column<
				2,
				1
			>(
				t
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			small_matrix_type(
				fcppt::math::matrix::row(
					1, 3
				),
				fcppt::math::matrix::row(
					4, 6
				),
				fcppt::math::matrix::row(
					10, 12
				)
			)
		);
	}

	{
		small_matrix_type const result{
			fcppt::math::matrix::delete_row_and_column<
				0,
				0
			>(
				t
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			small_matrix_type(
				fcppt::math::matrix::row(
					5, 6
				),
				fcppt::math::matrix::row(
					8, 9
				),
				fcppt::math::matrix::row(
					11, 12
				)
			)
		);
	}
}

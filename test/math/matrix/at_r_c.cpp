//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/object.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_at_r_c
)
{
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

	{
		int const result{
			fcppt::math::matrix::at_r_c<
				0,
				0
			>(
				mat
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			-3
		);
	}

	{
		int const result{
			fcppt::math::matrix::at_r_c<
				0,
				1
			>(
				mat
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			2
		);
	}

	{
		int const result{
			fcppt::math::matrix::at_r_c<
				1,
				0
			>(
				mat
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			-1
		);
	}

	{
		int const result{
			fcppt::math::matrix::at_r_c<
				1,
				1
			>(
				mat
			)
		};

		BOOST_CHECK_EQUAL(
			result,
			0
		);
	}
}

//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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


namespace
{

typedef
fcppt::math::matrix::static_<
	int,
	2,
	2
>
mat2;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_arithmetic_self
)
{
FCPPT_PP_POP_WARNING

	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		};

		left +=
			mat2{
				fcppt::math::matrix::row(
					5,6
				),
				fcppt::math::matrix::row(
					7,8
				)
			};

		BOOST_CHECK_EQUAL(
			left,
			mat2(
				fcppt::math::matrix::row(
					6,8
				),
				fcppt::math::matrix::row(
					10,12
				)
			)
		);
	}

	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		};

		left -=
			mat2{
				fcppt::math::matrix::row(
					2,4
				),
				fcppt::math::matrix::row(
					1,2
				)
			};

		BOOST_CHECK_EQUAL(
			left,
			mat2(
				fcppt::math::matrix::row(
					-1,-1
				),
				fcppt::math::matrix::row(
					2,3
				)
			)
		);
	}

	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		};

		left *=
			2;

		BOOST_CHECK_EQUAL(
			left,
			mat2(
				fcppt::math::matrix::row(
					2,4
				),
				fcppt::math::matrix::row(
					6,8
				)
			)
		);
	}
}


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_arithmetic_free
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		)
		+
		mat2(
			fcppt::math::matrix::row(
				5,6
			),
			fcppt::math::matrix::row(
				7,8
			)
		),
		mat2(
			fcppt::math::matrix::row(
				6,8
			),
			fcppt::math::matrix::row(
				10,12
			)
		)
	);

	BOOST_CHECK_EQUAL(
		mat2(
			fcppt::math::matrix::row(
				5,6
			),
			fcppt::math::matrix::row(
				7,8
			)
		)
		+
		mat2(
			fcppt::math::matrix::row(
				4,3
			),
			fcppt::math::matrix::row(
				2,1
			)
		),
		mat2(
			fcppt::math::matrix::row(
				1,3
			),
			fcppt::math::matrix::row(
				5,7
			)
		)
	);

	BOOST_CHECK_EQUAL(
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		)
		*
		2,
		mat2(
			fcppt::math::matrix::row(
				2,4
			),
			fcppt::math::matrix::row(
				6,8
			)
		)
	);

	BOOST_CHECK_EQUAL(
		2
		*
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4
			)
		),
		mat2(
			fcppt::math::matrix::row(
				2,4
			),
			fcppt::math::matrix::row(
				6,8
			)
		)
	);
}

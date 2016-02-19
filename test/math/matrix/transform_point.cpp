//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/transform_point.hpp>
#include <fcppt/math/matrix/translation.hpp>
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
	math_matrix_transform_point
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	vector_type;

	BOOST_CHECK_EQUAL(
		fcppt::math::matrix::transform_point(
			fcppt::math::matrix::translation(
				1,
				2,
				3
			),
			vector_type(
				4,
				5,
				6
			)
		),
		vector_type(
			5,
			7,
			9
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/object.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/std_hash.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_hash
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	int22_matrix;

	typedef
	std::unordered_set<
		int22_matrix
	>
	matrix_set;

	matrix_set set;

	set.insert(
		int22_matrix(
			fcppt::math::matrix::row(
				1,
				2
			),
			fcppt::math::matrix::row(
				3,
				4
			)
		)
	);

	BOOST_CHECK(
		set.count(
			int22_matrix(
				fcppt::math::matrix::row(
					1,
					2
				),
				fcppt::math::matrix::row(
					3,
					4
				)
			)
		)
		== 1u
	);

	BOOST_CHECK(
		set.count(
			int22_matrix(
				fcppt::math::matrix::row(
					4,
					2
				),
				fcppt::math::matrix::row(
					3,
					4
				)
			)
		)
		== 0u
	);
}

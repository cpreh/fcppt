//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/matrix/transform_direction.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_transform_direction
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	vector_type;

	BOOST_CHECK_EQUAL(
		fcppt::math::matrix::transform_direction(
			fcppt::math::matrix::scaling(
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
			4,
			10,
			18
		)
	);
}

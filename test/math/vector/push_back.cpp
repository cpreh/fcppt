//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/push_back.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_vector_push_back
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	i3_vector;

	i3_vector const vector(
		fcppt::math::vector::push_back(
			i2_vector(
				1,
				2
			),
			3
		)
	);

	BOOST_CHECK_EQUAL(
		i3_vector(
			1,
			2,
			3
		),
		vector
	);
}

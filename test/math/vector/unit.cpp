//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/unit.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_vector_unit
)
{
	typedef fcppt::math::vector::static_<
		int,
		3
	> int3_vector;

	int3_vector const vec(
		fcppt::math::vector::unit<
			int3_vector
		>(
			2
		)
	);

	BOOST_CHECK_EQUAL(
		vec.x(),
		0
	);

	BOOST_CHECK_EQUAL(
		vec.y(),
		0
	);

	BOOST_CHECK_EQUAL(
		vec.z(),
		1
	);
}

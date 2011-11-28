//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/basic.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/to_angle.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	vector_to_angle
)
{
	typedef fcppt::math::vector::static_<
		int,
		2
	>::type int2_vector;

	int2_vector const vec(
		1,
		0
	);

	typedef fcppt::optional<
		float
	> dest_type;

	dest_type const dest(
		fcppt::math::vector::to_angle<
			dest_type::value_type
		>(
			vec
		)
	);

	BOOST_REQUIRE(
		dest
	);

	float const epsilon = 0.0001f;

	BOOST_REQUIRE(
		std::abs(*dest) < epsilon);
}

//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/pi.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>

BOOST_AUTO_TEST_CASE(vector_swap)
{
	typedef fcppt::math::vector::static_<
		unsigned,
		2
	>::type ui2_vec;

	ui2_vec vec1(
		1u,
		2u
	);

	ui2_vec vec2(
		3u,
		4u
	);

	std::swap(
		vec1,
		vec2
	);

	BOOST_REQUIRE(
		vec1
		==
		ui2_vec(
			3u,
			4u
		)
	);

	BOOST_REQUIRE(
		vec2
		==
		ui2_vec(
			1u,
			2u
		)
	);
}

BOOST_AUTO_TEST_CASE(vector_unit_circle)
{
	typedef float float_type;

	typedef fcppt::math::vector::static_<
		float_type,
		2
	>::type vec_2f;

	BOOST_REQUIRE(
		fcppt::math::vector::unit_circle(
			fcppt::math::pi<
				float_type
			>()
		)
		==
		vec_2f(
			-1.f,
			0.f
		)
	);
}

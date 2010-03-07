//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/vector/static.hpp>
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

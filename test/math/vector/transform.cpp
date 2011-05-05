//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/transform.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

int
test(
	int const _arg
)
{
	return _arg * 2;
}

}

BOOST_AUTO_TEST_CASE(
	math_vector_transform
)
{
	typedef fcppt::math::vector::static_<
		int,
		2
	>::type vector_int2;

	vector_int2 const result(
		fcppt::math::vector::transform(
			vector_int2(
				1,
				2
			),
			test
		)
	);

	BOOST_REQUIRE(
		result[0] == 2
		&& result[1] == 4
	);
}

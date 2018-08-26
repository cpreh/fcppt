//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector comparison",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	uivector2;

	uivector2 const
		vec1(1u, 2u),
		vec2(1u, 2u),
		vec3(2u, 2u);

	CHECK(
		vec1
		==
		vec2
	);

	CHECK(
		vec2
		!=
		vec3
	);

	CHECK(
		vec1
		<
		vec3
	);
}

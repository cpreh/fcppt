//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::hash",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	int3_vector;

	typedef
	std::unordered_set<
		int3_vector
	>
	vector_set;

	vector_set const set{
		int3_vector(
			1,
			2,
			3
		)
	};

	CHECK(
		set.count(
			int3_vector(
				1,
				2,
				3
			)
		)
		==
		1u
	);

	CHECK(
		set.count(
			int3_vector(
				4,
				2,
				3
			)
		)
		==
		0u
	);
}

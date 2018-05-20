//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim::hash",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		3
	>
	int3_dim;

	typedef
	std::unordered_set<
		int3_dim
	>
	dim_set;

	dim_set const set{
		int3_dim(
			1,
			2,
			3
		)
	};

	CHECK(
		set.count(
			int3_dim(
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
			int3_dim(
				4,
				2,
				3
			)
		)
		==
		0u
	);
}

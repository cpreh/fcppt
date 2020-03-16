//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/contains.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::contains",
	"[container]"
)
{
	typedef
	std::set<
		int
	>
	int_set;

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	int_set const ints{
		1,2,3
	};

	CHECK(
		fcppt::container::contains(
			ints,
			1
		)
	);

	CHECK_FALSE(
		fcppt::container::contains(
			ints,
			4
		)
	);
}

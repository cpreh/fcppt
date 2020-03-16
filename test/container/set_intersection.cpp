//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/set_intersection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::set_intersection",
	"[container]"
)
{
	using
	int_set
	=
	std::set<
		int
	>;

	CHECK(
		fcppt::container::set_intersection(
			int_set{ // NOLINT(fuchsia-default-arguments-calls)
				1, 2, 3
			},
			int_set{ // NOLINT(fuchsia-default-arguments-calls)
				2, 3, 4
			}
		)
		==
		int_set{ // NOLINT(fuchsia-default-arguments-calls)
			2, 3
		}
	);
}

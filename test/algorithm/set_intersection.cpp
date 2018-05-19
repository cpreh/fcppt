//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/set_intersection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::set_intersection",
	"[algorithm]"
)
{
	typedef
	std::set<
		int
	>
	int_set;

	CHECK(
		fcppt::algorithm::set_intersection(
			int_set{
				1, 2, 3
			},
			int_set{
				2, 3, 4
			}
		)
		==
		int_set{
			2, 3
		}
	);
}

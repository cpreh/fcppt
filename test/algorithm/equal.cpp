//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/equal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <list>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm equal"
	"[algorithm]"
)
{
	CHECK(
		fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1,
				2
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);

	CHECK_FALSE(
		fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);

	CHECK_FALSE(
		fcppt::algorithm::equal(
			std::vector<
				int
			>{
				1,
				3
			},
			std::list<
				int
			>{
				1,
				2
			}
		)
	);
}

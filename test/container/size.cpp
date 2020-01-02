//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <list>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::size",
	"[container]"
)
{
	CHECK(
		fcppt::container::size(
			std::list<
				int
			>{
				1,
				2,
				3,
				4
			}
		)
		==
		4u
	);

	CHECK(
		fcppt::container::size(
			std::vector<
				int
			>{
				1,
				2
			}
		)
		==
		2u
	);

}

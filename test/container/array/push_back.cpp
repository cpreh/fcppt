//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::push_back",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::push_back(
			std::array<
				int,
				3
			>{{
				1,
				2,
				3
			}},
			4
		)
		==
		std::array<
			int,
			4
		>{{
			1,
			2,
			3,
			4
		}}
	);
}

TEST_CASE(
	"array::push_back move",
	"[container],[array]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	CHECK(
		fcppt::container::array::push_back(
			std::array<
				int_movable,
				1
			>{{
				int_movable{
					1
				}
			}},
			int_movable{
				2
			}
		)
		==
		std::array<
			int_movable,
			2
		>{{
			int_movable{
				1
			},
			int_movable{
				2
			}
		}}
	);
}

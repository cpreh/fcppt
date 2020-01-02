//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/join.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::join",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::join(
			std::array<
				int,
				2
			>{{
				1, 2
			}},
			std::array<
				int,
				3
			>{{
				3, 4, 5
			}},
			std::array<
				int,
				2
			>{{
				6, 7
			}}

		)
		==
		std::array<
			int,
			7
		>{{
			1, 2, 3, 4, 5, 6, 7
		}}
	);
}

TEST_CASE(
	"array::join move",
	"[container],[array]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	CHECK(
		fcppt::container::array::join(
			std::array<
				int_movable,
				2
			>{{
				int_movable{1},
				int_movable{2}
			}},
			std::array<
				int_movable,
				3
			>{{
				int_movable{3},
				int_movable{4},
				int_movable{5}
			}},
			std::array<
				int_movable,
				2
			>{{
				int_movable{6},
				int_movable{7}
			}}
		)
		==
		std::array<
			int_movable,
			7
		>{{
			int_movable{1},
			int_movable{2},
			int_movable{3},
			int_movable{4},
			int_movable{5},
			int_movable{6},
			int_movable{7}
		}}
	);
}

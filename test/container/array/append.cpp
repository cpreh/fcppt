//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/append.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::append",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::append(
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
			}}
		)
		==
		std::array<
			int,
			5
		>{{
			1, 2, 3, 4, 5
		}}
	);
}

TEST_CASE(
	"array::append move",
	"[container],[array]"
)
{
	using
	int_movable
	=
	fcppt::catch_::movable<
		int
	>;

	CHECK(
		fcppt::container::array::append(
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
			}}
		)
		==
		std::array<
			int_movable,
			5
		>{{
			int_movable{1},
			int_movable{2},
			int_movable{3},
			int_movable{4},
			int_movable{5}
		}}
	);
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/apply.hpp>
#include <fcppt/container/array/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::apply",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::apply(
			[](
				int const _value1,
				bool const _value2
			)
			{
				return
					std::make_pair(
						_value1,
						_value2
					);
			},
			fcppt::container::array::make(
				1,
				2
			),
			fcppt::container::array::make(
				true,
				false
			)
		)
		==
		std::array<
			std::pair<
				int,
				bool
			>,
			2
		>{{
			std::make_pair(
				1,
				true
			),
			std::make_pair(
				2,
				false
			)
		}}
	);
}

TEST_CASE(
	"array::apply move",
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
		fcppt::container::array::apply(
			[](
				int_movable &&_arg1,
				int_movable &&_arg2
			)
			{
				return
					std::make_pair(
						std::move(
							_arg1
						),
						std::move(
							_arg2
						)
					);
			},
			fcppt::container::array::make(
				int_movable{
					1
				}
			),
			fcppt::container::array::make(
				int_movable{
					2
				}
			)
		)
		==
		std::array<
			std::pair<
				int_movable,
				int_movable
			>,
			1
		>{{
			std::make_pair(
				int_movable{
					1
				},
				int_movable{
					2
				}
			)
		}}
	);
}

TEST_CASE(
	"array::apply empty",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::apply(
			[](
				bool,
				int
			)
			{
				return
					fcppt::unit{};
			},
			std::array<
				bool,
				0
			>{},
			std::array<
				int,
				0
			>{}
		)
		==
		std::array<
			fcppt::unit,
			0
		>{}
	);
}

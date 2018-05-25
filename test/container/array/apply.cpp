//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/container/array/apply.hpp>
#include <fcppt/container/array/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <catch.hpp>
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
	typedef
	std::array<
		std::pair<
			fcppt::unique_ptr<
				int
			>,
			fcppt::unique_ptr<
				int
			>
		>,
		1
	>
	result_array;

	result_array const result(
		fcppt::container::array::apply(
			[](
				fcppt::unique_ptr<
					int
				> &&_arg1,
				fcppt::unique_ptr<
					int
				> &&_arg2
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
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			),
			fcppt::container::array::make(
				fcppt::make_unique_ptr<
					int
				>(
					2
				)
			)
		)
	);

	CHECK(
		*std::get<
			0
		>(
			result
		).first
		==
		1
	);

	CHECK(
		*std::get<
			0
		>(
			result
		).second
		==
		2
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

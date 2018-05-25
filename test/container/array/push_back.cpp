//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/array/make.hpp>
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
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	std::array<
		int_unique_ptr,
		2
	> const result(
		fcppt::container::array::push_back(
			fcppt::container::array::make(
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			),
			fcppt::make_unique_ptr<
				int
			>(
				2
			)
		)
	);

	CHECK(
		*std::get<
			0
		>(
			result
		)
		==
		1
	);

	CHECK(
		*std::get<
			1
		>(
			result
		)
		==
		2
	);
}

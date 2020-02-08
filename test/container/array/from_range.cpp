//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/optional.hpp>
#include <fcppt/container/array/from_range.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"array::from_range",
	"[container],[array]"
)
{
	CHECK(
		fcppt::container::array::from_range<
			2
		>(
			std::vector<
				int
			>{
				1,
				2
			}
		)
		==
		fcppt::optional::make(
			std::array<
				int,
				2
			>{{
				1,
				2
			}}
		)
	);

	CHECK(
		fcppt::container::array::from_range<
			2
		>(
			std::vector<
				int
			>{
				1,
				2,
				3
			}
		)
		==
		fcppt::optional::object<
			std::array<
				int,
				2
			>
		>()
	);
}

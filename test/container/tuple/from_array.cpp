//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tuple/from_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tuple::from_array",
	"[container],[tuple]"
)
{
	CHECK(
		fcppt::container::tuple::from_array(
			std::array<
				int,
				3
			>{{
				1,
				2,
				3,
			}}
		)
		==
		std::make_tuple(
			1,
			2,
			3
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/move_clear.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"move_clear",
	"[various]"
)
{
	using
	int_vector
	=
	std::vector<
		int
	>;

	int_vector ints{
		1,2
	};

	int_vector moved(
		fcppt::move_clear(
			ints
		)
	);

	CHECK(
		moved
		==
		int_vector{
			1,
			2
		}
	);

	CHECK(
		ints.empty()
	);
}

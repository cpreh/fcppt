//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/index_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::index_map",
	"[container]"
)
{
	using
	int_index_map
	=
	fcppt::container::index_map<
		int
	>;

	int_index_map map{};

	map[
		2
	] = 42; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	REQUIRE(
		map.impl().size()
		==
		3U
	);

	CHECK(
		map[0]
		==
		0
	);

	CHECK(
		map[1]
		==
		0
	);

	CHECK(
		map[2]
		==
		42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

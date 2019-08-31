//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/range/begin.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"range::begin",
	"[range]"
)
{
	int array[3] = { 0, 0, 0 };

	CHECK(
		fcppt::range::begin(
			array
		)
		==
		&array[0]
	);
}

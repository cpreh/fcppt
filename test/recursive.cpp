//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_recursive.hpp>
#include <fcppt/recursive_comparison.hpp>
#include <fcppt/recursive_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"recursive",
	"[various]"
)
{
	CHECK(
		fcppt::make_recursive(
			10
		)
		==
		fcppt::make_recursive(
			10
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::nothing",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int const result{
		fcppt::optional::nothing{}
	};

	CHECK(
		result
		==
		optional_int{}
	);
}

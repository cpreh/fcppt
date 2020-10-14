//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/extract_from_string.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"extract_from_string",
	"[string]"
)
{
	using
	opt_int
	=
	fcppt::optional::object<
		int
	>;

	CHECK(
		fcppt::extract_from_string<
			int
		>(
			std::string(
				"42"
			)
		)
		==
		opt_int{
			42
		}
	);

	CHECK(
		fcppt::extract_from_string<
			int
		>(
			std::string(
				"abc"
			)
		)
		==
		opt_int{}
	);
}

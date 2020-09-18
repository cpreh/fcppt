//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::skipper::epsilon",
	"[parse]"
)
{
	fcppt::parse::skipper::epsilon const parser{};

	CHECK(
		fcppt::test::parse::skipper::skip_string(
			parser,
			std::string{}
		)
		==
		fcppt::parse::skipper::make_success<
			char
		>()
	);

	CHECK(
		fcppt::test::parse::skipper::skip_string(
			parser,
			std::string{
				"X"
			}
		).has_failure()
	);
}

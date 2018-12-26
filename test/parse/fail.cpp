//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/fail.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::fail",
	"[parse]"
)
{
	fcppt::parse::fail<
		fcppt::unit
	> const parser{};

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::optional::object<
			fcppt::unit
		>{}
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::optional::object<
			fcppt::unit
		>{}
	);
}

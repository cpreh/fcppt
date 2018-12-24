//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/parse/basic_char.hpp>
#include <fcppt/parse/no_skipper.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::basic_char",
	"[parse]"
)
{
	fcppt::parse::basic_char<
		char
	> const parser{};

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::no_skipper{}
		)
		==
		fcppt::optional::object<
			char
		>{}
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			},
			fcppt::parse::no_skipper{}
		)
		==
		fcppt::optional::make(
			'X'
		)
	);
}

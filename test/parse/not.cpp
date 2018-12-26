//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/operators/not.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::not",
	"[parse]"
)
{
	auto const parser{
		!fcppt::parse::literal{
			'X'
		}
		>>
		fcppt::parse::char_{}
	};

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"XY"
			},
			fcppt::parse::epsilon()
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
				"Y"
			},
			fcppt::parse::epsilon()
		)
		==
		fcppt::optional::make(
			'Y'
		)
	);
}

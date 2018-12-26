//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::char_set",
	"[parse]"
)
{
	fcppt::parse::char_set const parser{
		'a', 'b', 'c'
	};

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::epsilon{}
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
				"d"
			},
			fcppt::parse::epsilon{}
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
				"a"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::optional::make(
			'a'
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"b"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::optional::make(
			'b'
		)
	);
}

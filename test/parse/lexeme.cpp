//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::lexeme",
	"[parse]"
)
{
	auto const parser{
		fcppt::parse::make_lexeme(
			*fcppt::parse::char_{}
		)
	};

	typedef
	fcppt::parse::result_of<
		decltype(
			parser
		)
	>
	result_type;

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				" ab "
			},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::optional::make(
			result_type{
				' ', 'a', 'b', ' '
			}
		)
	);
}

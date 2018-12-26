//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::construct",
	"[parse]"
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		char,
		strong_char
	);

	auto const parser(
		fcppt::parse::construct<
			strong_char
		>(
			fcppt::parse::char_{}
		)
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
		fcppt::optional::make(
			strong_char{
				'X'
			}
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/no_skipper.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::repetition",
	"[parse]"
)
{
	auto const parser{
		*fcppt::parse::char_{}
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
			"",
			fcppt::parse::no_skipper()
		)
		==
		fcppt::optional::make(
			result_type{}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			"XYZ",
			fcppt::parse::no_skipper()
		)
		==
		fcppt::optional::make(
			result_type{
				'X', 'Y', 'Z'
			}
		)
	);
}

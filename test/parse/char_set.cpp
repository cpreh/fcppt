//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
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
			fcppt::parse::skipper::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"d"
			},
			fcppt::parse::skipper::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"a"
			},
			fcppt::parse::skipper::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			'a'
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"b"
			},
			fcppt::parse::skipper::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			'b'
		)
	);
}

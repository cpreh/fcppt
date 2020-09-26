//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::base",
	"[parse]"
)
{
	fcppt::parse::base_unique_ptr<
		std::string,
		char,
		fcppt::parse::skipper::epsilon
	> const parser{
		fcppt::parse::make_base<
			char,
			fcppt::parse::skipper::epsilon
		>(
			*fcppt::parse::char_{}
		)
	};

	CHECK(
		fcppt::parse::parse_string(
			*parser,
			std::string{
				"XY"
			}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::string{
				"XY"
			}
		)
	);

	CHECK(
		fcppt::parse::phrase_parse_string(
			*parser,
			std::string{
				"XY"
			},
			fcppt::parse::skipper::epsilon()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::string{
				"XY"
			}
		)
	);

}

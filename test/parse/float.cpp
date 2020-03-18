//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/float.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::float",
	"[parse]"
)
{
	using Catch::literals:: operator""_a;

	fcppt::parse::float_<

		float
	> const parser{};

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				" 1.5"
			},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	fcppt::either::match(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"1.5"
			},
			fcppt::parse::epsilon{}
		),
		[](
			fcppt::parse::error<
				char
			> const &
		){
			CHECK(
				false
			);
		},
		[](
			float const _value
		)
		{
			CHECK(
				_value
				==
				1.5_a // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			);
		}
	);
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_recursive.hpp>
#include <fcppt/recursive_comparison.hpp>
#include <fcppt/recursive_output.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/recursive.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::sequence",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::char_{}
		>>
		fcppt::parse::char_{}
		>>
		fcppt::parse::char_{}
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"XYZ"
			}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::make_tuple(
				'X',
				'Y',
				'Z'
			)
		)
	);
}

TEST_CASE(
	"parse::sequence move",
	"[parse]"
)
{
	using
	inner_type
	=
	fcppt::parse::recursive<
		fcppt::parse::char_
	>;

	auto const parser(
		inner_type{
			fcppt::parse::char_{}
		}
		>>
		inner_type{
			fcppt::parse::char_{}
		}
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{"XY"}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::make_tuple(
				fcppt::make_recursive(
					'X'
				),
				fcppt::make_recursive(
					'Y'
				)
			)
		)
	);
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/parse/uint.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::uint",
	"[parse]"
)
{
	fcppt::parse::uint_<
		unsigned
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
				" 42"
			},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"42"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			42U
		)
	);
}

TEST_CASE(
	"parse::uint sequence",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::uint_<
			unsigned
		>{}
		>>
		fcppt::parse::literal{
			','
		}
		>>
		fcppt::parse::uint_<
			unsigned
		>{}
	);

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
				"12, 3"
			},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::make_tuple(
				12U,
				3U
			)
		)
	);
}

TEST_CASE(
	"parse::uint vector",
	"[parse]"
)
{
	auto const parser{
		*fcppt::parse::uint_<
			unsigned
		>{}
	};

	using
	result_type
	=
	fcppt::parse::result_of<
		decltype(
			parser
		)
	>;

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"10 20"
			},
			fcppt::parse::space_skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				10U,
				20U
			}
		)
	);
}

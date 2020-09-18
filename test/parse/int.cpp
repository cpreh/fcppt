//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::int",
	"[parse]"
)
{
	fcppt::parse::int_<
		int
	> const parser{};

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
				"X"
			},
			fcppt::parse::skipper::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				" 42"
			},
			fcppt::parse::skipper::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"42"
			},
			fcppt::parse::skipper::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			42
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"-42"
			},
			fcppt::parse::skipper::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			-42
		)
	);
}

TEST_CASE(
	"parse::int sequence",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::int_<
			int
		>{}
		>>
		fcppt::parse::literal{
			','
		}
		>>
		fcppt::parse::int_<
			int
		>{}
	);

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
				"12, 3"
			},
			fcppt::parse::skipper::space()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			std::make_tuple(
				12,
				3
			)
		)
	);
}

TEST_CASE(
	"parse::int vector",
	"[parse]"
)
{
	auto const parser{
		*fcppt::parse::int_<
			int
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
			fcppt::parse::skipper::space()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				10,
				20
			}
		)
	);
}

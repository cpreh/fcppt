//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/uint.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::uint", "[parse]")
{
  fcppt::parse::uint<unsigned> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{" 42"}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"42"}) ==
      fcppt::parse::make_success<char>(42U));
}

TEST_CASE("parse::uint sequence", "[parse]")
{
  auto const parser(
      fcppt::parse::uint<unsigned>{} >> fcppt::parse::literal{','} >>
      fcppt::parse::uint<unsigned>{});

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"12, 3"}, fcppt::parse::skipper::space()) ==
      fcppt::parse::make_success<char>(fcppt::tuple::make(12U, 3U)));
}

TEST_CASE("parse::uint vector", "[parse]")
{
  auto const parser{*fcppt::parse::uint<unsigned>{}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"10 20"}, fcppt::parse::skipper::space()) ==
      fcppt::parse::make_success<char>(result_type{10U, 20U}));
}

FCPPT_CATCH_END

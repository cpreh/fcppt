//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/string.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("parse::string", "[parse]")
{
  fcppt::parse::string const parser{std::string{"test"}};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test"}) ==
      fcppt::parse::make_success<char>(fcppt::unit{}));

  CHECK(fcppt::parse::parse_string(parser, std::string{"te"}).has_failure());
}

TEST_CASE("parse::string sequence", "[parse]")
{
  auto const parser{
      fcppt::parse::string{std::string{"test1"}} >> fcppt::parse::string{std::string{"test2"}}};

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test1test2"}) ==
      fcppt::parse::make_success<char>(fcppt::unit{}));
}

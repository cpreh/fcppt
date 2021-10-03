//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/float.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::float", "[parse]")
{
  using Catch::literals::operator""_a;

  fcppt::parse::float_<float> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{" 1.5"}).has_failure());

  fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{"1.5"}),
      [](fcppt::parse::error<char> const &) { CHECK(false); },
      [](float const _value) { CHECK(_value == 1.5_a); });

  fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{"-1.5"}),
      [](fcppt::parse::error<char> const &) { CHECK(false); },
      [](float const _value) { CHECK(_value == -1.5_a); });
}

FCPPT_CATCH_END

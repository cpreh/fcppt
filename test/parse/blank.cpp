//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/blank.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("parse::char_set", "[parse]")
{
  auto const parser{fcppt::parse::blank()};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{' '}) ==
      fcppt::parse::make_success<char>(' '));
}

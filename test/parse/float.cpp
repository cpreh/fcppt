//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp> // IWYU pragma: keep
#include <fcppt/either/match.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/parse/float.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::float", "[parse]")
{
  using Catch::literals::operator""_a;

  fcppt::parse::float_<float> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{" 1.5"}).has_failure());

  fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{"1.5"}),
      [](fcppt::parse::parse_string_error<char> const &) { CHECK(false); },
      [](float const _value) { CHECK(_value == 1.5_a); });

  fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{"-1.5"}),
      [](fcppt::parse::parse_string_error<char> const &) { CHECK(false); },
      [](float const _value) { CHECK(_value == -1.5_a); });
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

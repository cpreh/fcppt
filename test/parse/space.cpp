//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/parse/space.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::space", "[parse]")
{
  auto const parser{fcppt::parse::space()};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{' '}) ==
      fcppt::parse::make_parse_string_success<char>(' '));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/no_error_comparison.hpp> // IWYU pragma: keep
#include <fcppt/either/no_error_output.hpp> // IWYU pragma: keep
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/skipper/comment.hpp>
#include <fcppt/parse/skipper/string.hpp>
#include <fcppt/test/parse/skipper/make_success.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::skipper::comment", "[parse]")
{
  fcppt::parse::skipper::comment const parser{
    fcppt::parse::skipper::string{"/*"},
    fcppt::parse::skipper::string{"*/"}
  };

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{}).has_failure());
  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{"/* XY"}).has_failure());
  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"/* XY */"}) ==
      fcppt::test::parse::skipper::make_success<char>());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/unit_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/parse/basic_string.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/string.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::string", "[parse]")
{
  fcppt::parse::string const parser{std::string{"test"}};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test"}) ==
      fcppt::parse::make_parse_string_success<char>(fcppt::unit{}));

  CHECK(fcppt::parse::parse_string(parser, std::string{"te"}).has_failure());
}

TEST_CASE("parse::wstring", "[parse]")
{
  fcppt::parse::basic_string<wchar_t> const parser{std::wstring{L"test"}};

  CHECK(fcppt::parse::parse_string(parser, std::wstring{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::wstring{L"test"}) ==
      fcppt::parse::make_parse_string_success<wchar_t>(fcppt::unit{}));

  CHECK(fcppt::parse::parse_string(parser, std::wstring{L"te"}).has_failure());
}

TEST_CASE("parse::string sequence", "[parse]")
{
  auto const parser{
      fcppt::parse::string{std::string{"test1"}} >> fcppt::parse::string{std::string{"test2"}}};

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test1test2"}) ==
      fcppt::parse::make_parse_string_success<char>(fcppt::unit{}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

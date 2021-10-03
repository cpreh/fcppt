//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::char", "[parse]")
{
  fcppt::parse::char_ const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_success<char>('X'));
}

TEST_CASE("parse::wchar", "[parse]")
{
  fcppt::parse::basic_char<wchar_t> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::wstring{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::wstring{L"X"}) ==
      fcppt::parse::make_success<wchar_t>(L'X'));
}

FCPPT_CATCH_END

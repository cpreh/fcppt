//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/strong_typedef.hpp> // IWYU pragma: keep
#include <fcppt/catch/tuple.hpp> // IWYU pragma: keep
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/basic_char_set.hpp>
#include <fcppt/parse/basic_literal.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/separator.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/comparison.hpp> // IWYU pragma: keep
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::separator", "[parse]")
{
  fcppt::parse::separator const parser{+~fcppt::parse::char_set{','}, fcppt::parse::literal{','}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::string{}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{std::string{"test"}}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"test1,test2,test3"}) ==
      fcppt::parse::make_parse_string_success<char>(
          result_type{std::string{"test1"}, std::string{"test2"}, std::string{"test3"}}));
}

TEST_CASE("parse::separator sequence", "[parse]")
{
  fcppt::parse::separator const parser{
      +~fcppt::parse::char_set{',', '='} >> fcppt::parse::literal{'='} >> fcppt::parse::int_<int>{},
      fcppt::parse::literal{','}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X=1,Y=2"}) ==
      fcppt::parse::make_parse_string_success<char>(
          result_type{fcppt::tuple::make(std::string{"X"}, 1), fcppt::tuple::make(std::string{"Y"}, 2)}));
}

TEST_CASE("parse::separator wchar", "[parse]")
{
  fcppt::parse::separator const parser{
      +~fcppt::parse::basic_char_set<wchar_t>{L','}, fcppt::parse::basic_literal<wchar_t>{L','}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::wstring{L"test1,test2"}) ==
      fcppt::parse::make_parse_string_success<wchar_t>(
          result_type{std::wstring{L"test1"}, std::wstring{L"test2"}}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

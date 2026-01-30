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
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/tuple/comparison.hpp> // IWYU pragma: keep
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::int", "[parse]")
{
  fcppt::parse::int_<int> const parser{};

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{" 42"}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"42"}) ==
      fcppt::parse::make_parse_string_success<char>(42));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"-42"}) ==
      fcppt::parse::make_parse_string_success<char>(-42));
}

TEST_CASE("parse::int sequence", "[parse]")
{
  auto const parser(
      fcppt::parse::int_<int>{} >> fcppt::parse::literal{','} >> fcppt::parse::int_<int>{});

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"12, 3"}, fcppt::parse::skipper::space()) ==
      fcppt::parse::make_parse_string_success<char>(fcppt::tuple::make(12, 3)));
}

TEST_CASE("parse::int vector", "[parse]")
{
  auto const parser{*fcppt::parse::int_<int>{}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"10 20"}, fcppt::parse::skipper::space()) ==
      fcppt::parse::make_parse_string_success<char>(result_type{10, 20}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

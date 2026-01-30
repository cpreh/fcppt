//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/unit_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/variant/comparison.hpp> // IWYU pragma: keep
#include <fcppt/variant/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::alternative", "[parse]")
{
  auto const parser(fcppt::parse::int_<int>{} | fcppt::parse::literal{'X'} | fcppt::parse::char_{});

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"42"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{42}));
}

TEST_CASE("parse::alternative backtrack", "[parse]")
{
  auto const parser(fcppt::parse::literal{'X'} | fcppt::parse::char_{});

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{fcppt::unit()}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"Y"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{'Y'}));
}

TEST_CASE("parse::alternative fatal", "[parse]")
{
  auto const parser(fcppt::parse::make_fatal(fcppt::parse::literal{'X'}) | fcppt::parse::char_{});

  CHECK(fcppt::parse::parse_string(parser, std::string{"Y"}).has_failure());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

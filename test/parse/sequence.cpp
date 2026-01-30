//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_recursive.hpp>
#include <fcppt/recursive_comparison.hpp> // IWYU pragma: keep
#include <fcppt/recursive_output.hpp> // IWYU pragma: keep
#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/recursive.hpp> // IWYU pragma: keep
#include <fcppt/catch/tuple.hpp> // IWYU pragma: keep
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_parse_string_success.hpp> // IWYU pragma: keep
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/recursive.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/comparison.hpp> // IWYU pragma: keep
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::sequence", "[parse]")
{
  auto const parser(fcppt::parse::char_{} >> fcppt::parse::char_{} >> fcppt::parse::char_{});

  CHECK(fcppt::parse::parse_string(parser, std::string{}).has_failure());

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"XYZ"}) ==
      fcppt::parse::make_parse_string_success<char>(fcppt::tuple::make('X', 'Y', 'Z')));
}

TEST_CASE("parse::sequence move", "[parse]")
{
  using inner_type = fcppt::parse::recursive<fcppt::parse::char_>;

  auto const parser(inner_type{fcppt::parse::char_{}} >> inner_type{fcppt::parse::char_{}});

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"XY"}) ==
      fcppt::parse::make_parse_string_success<char>(
          fcppt::tuple::make(fcppt::make_recursive('X'), fcppt::make_recursive('Y'))));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

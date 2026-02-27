//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/comparison.hpp> // IWYU pragma: keep
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::repetition", "[parse]")
{
  auto const parser{*fcppt::parse::char_{}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::string{}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"XYZ"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{'X', 'Y', 'Z'}));
}

TEST_CASE("parse::repetition backtrack", "[parse]")
{
  auto const parser{*fcppt::parse::literal{'X'} >> fcppt::parse::char_{}};

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"XXXY"}) ==
      fcppt::parse::make_parse_string_success<char>(fcppt::tuple::make(
          std::vector<fcppt::unit>{fcppt::unit{}, fcppt::unit{}, fcppt::unit{}}, 'Y')));
}

TEST_CASE("parse::repetition fatal", "[parse]")
{
  auto const parser{*fcppt::parse::make_fatal(fcppt::parse::literal{'X'})};

  CHECK(fcppt::parse::parse_string(parser, std::string{"XXYX"}).has_failure());
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

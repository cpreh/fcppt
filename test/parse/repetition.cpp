//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

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

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/optional.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::optional", "[parse]")
{
  auto const parser{-fcppt::parse::char_{}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::string{}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{'X'}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{'X'}));
}

TEST_CASE("parse::optional backtrack", "[parse]")
{
  auto const parser{-fcppt::parse::int_<int>{} >> fcppt::parse::char_{}};

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_parse_string_success<char>(
          fcppt::tuple::make(fcppt::optional::object<int>{}, 'X')));
}

TEST_CASE("parse::optional fatal", "[parse]")
{
  auto const parser{-fcppt::parse::make_fatal(fcppt::parse::int_<int>{})};

  CHECK(fcppt::parse::parse_string(parser, std::string{"X"}).has_failure());
}

FCPPT_CATCH_END

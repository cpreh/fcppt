//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/no_error_comparison.hpp>
#include <fcppt/parse/skipper/literal.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/operators/repetition.hpp>
#include <fcppt/parse/skipper/operators/sequence.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("parse::skipper::repetition", "[parse]")
{
  auto const parser{*fcppt::parse::skipper::literal{'X'}};

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{}) ==
      fcppt::parse::skipper::make_success<char>());

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"XXX"}) ==
      fcppt::parse::skipper::make_success<char>());
}

TEST_CASE("parse::skipper::repetition backtrack", "[parse]")
{
  auto const parser{*fcppt::parse::skipper::literal{'X'} >> fcppt::parse::skipper::literal{'Y'}};

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"XXXY"}) ==
      fcppt::parse::skipper::make_success<char>());
}

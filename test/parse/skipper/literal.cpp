//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/no_error_comparison.hpp>
#include <fcppt/either/no_error_output.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/skipper/literal.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::skipper::literal", "[parse]")
{
  fcppt::parse::skipper::literal const parser{'X'};

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{}).has_failure());

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"X"}) ==
      fcppt::parse::skipper::make_success<char>());

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{"Y"}).has_failure());
}

FCPPT_CATCH_END

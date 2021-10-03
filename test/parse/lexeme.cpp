//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("parse::lexeme", "[parse]")
{
  auto const parser{fcppt::parse::make_lexeme(*fcppt::parse::char_{})};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"a b "}, fcppt::parse::skipper::space()) ==
      fcppt::parse::make_success<char>(result_type{'a', ' ', 'b', ' '}));
}

FCPPT_CATCH_END

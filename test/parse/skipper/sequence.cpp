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
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/skipper/literal.hpp>
#include <fcppt/parse/skipper/operators/sequence.hpp>
#include <fcppt/test/parse/skipper/make_success.hpp>
#include <fcppt/test/parse/skipper/skip_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::skipper::sequence", "[parse]")
{
  auto const parser(
      fcppt::parse::skipper::literal{'X'} >> fcppt::parse::skipper::literal{'Y'} >>
      fcppt::parse::skipper::literal{'Z'});

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{}).has_failure());

  CHECK(fcppt::test::parse::skipper::skip_string(parser, std::string{"X"}).has_failure());

  CHECK(
      fcppt::test::parse::skipper::skip_string(parser, std::string{"XYZ"}) ==
      fcppt::test::parse::skipper::make_success<char>());
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

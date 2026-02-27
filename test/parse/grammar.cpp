//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/parse/grammar.hpp>
#include <fcppt/parse/grammar_parse_stream.hpp>
#include <fcppt/parse/grammar_parse_string.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/make_parse_stream_success.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_stream_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/skipper/space.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
using skipper = decltype(fcppt::parse::skipper::space());

class grammar : public fcppt::parse::grammar<int, char, skipper>
{
  FCPPT_NONMOVABLE(grammar);

public:
  grammar();

  ~grammar(); // NOLINT(bugprone-derived-method-shadowing-base-method)

private:
  grammar_base::base_type<int> start_;
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

grammar::grammar()
    : grammar_base{fcppt::make_cref(this->start_), fcppt::parse::skipper::space()},
      start_{grammar_base::make_base(fcppt::parse::int_<int>{})}
{
}

FCPPT_PP_POP_WARNING

grammar::~grammar() = default;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::grammar string", "[parse]")
{
  CHECK(
      fcppt::parse::grammar_parse_string(std::string{" 42"}, grammar{}) ==
      fcppt::parse::make_parse_string_success<char>(42));
}

TEST_CASE("parse::grammar stream", "[parse]")
{
  std::istringstream stream{std::string{" 42"}};

  CHECK(
      fcppt::parse::grammar_parse_stream(stream, grammar{}) ==
      fcppt::parse::make_parse_stream_success<char>(42));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

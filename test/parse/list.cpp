//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/list.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::list", "[parse]")
{
  fcppt::parse::list const parser{
      fcppt::parse::literal{'['},
      fcppt::parse::make_fatal(~fcppt::parse::char_set{',', ']'}),
      fcppt::parse::literal{','},
      fcppt::parse::literal{']'}};

  using result_type = fcppt::parse::result_of<decltype(parser)>;

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"[]"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"[a,b]"}) ==
      fcppt::parse::make_parse_string_success<char>(result_type{'a', 'b'}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

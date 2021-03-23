//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/either.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/list.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

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
      fcppt::parse::make_success<char>(result_type{}));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"[a,b]"}) ==
      fcppt::parse::make_success<char>(result_type{'a', 'b'}));
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("catch::record", "[catch]")
{
  FCPPT_RECORD_MAKE_LABEL(string_label);

  using record = fcppt::record::object<fcppt::record::element<string_label, fcppt::string>>;

  CHECK(
      record{string_label{} = fcppt::string{FCPPT_TEXT("test")}} ==
      record{string_label{} = fcppt::string{FCPPT_TEXT("test")}});
}

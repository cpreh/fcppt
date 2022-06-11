//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("catch::either", "[catch]")
{
  FCPPT_DECLARE_STRONG_TYPEDEF(fcppt::string, strong_typedef);

  CHECK(
      strong_typedef{fcppt::string{FCPPT_TEXT("test")}} ==
      strong_typedef{fcppt::string{FCPPT_TEXT("test")}});
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("catch::tuple", "[catch]")
{
  CHECK(
      fcppt::catch_::convert(fcppt::tuple::make(10)) ==
      std::string{"{ 10 }"});
}

FCPPT_CATCH_END

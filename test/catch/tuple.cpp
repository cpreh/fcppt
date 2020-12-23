//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER

#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("catch::optional", "[catch]")
{
  CHECK(
      fcppt::catch_::convert(fcppt::tuple::make(10)) ==
      std::string{"{ 10 }"});
}

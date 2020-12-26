//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object.hpp>
#include <fcppt/catch/array.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("catch::array", "[catch]")
{
  CHECK(
      fcppt::catch_::convert(fcppt::array::object<int,2>{1,2}) ==
      std::string{"{ 1, 2 }"});
}

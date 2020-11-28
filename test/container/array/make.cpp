//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/array/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("array::make", "[container],[array]")
{
  std::string const string_ref{"100"};

  CHECK(
      fcppt::container::array::make(std::string{"42"}, string_ref) ==
      std::array<std::string, 2>{{std::string{"42"}, std::string{"100"}}});
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/get.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("array::array", "[array]")
{
  fcppt::array::object<int,2U> const test{4,8};

  CHECK(fcppt::array::get<0>(test) == 4);
  CHECK(fcppt::array::get<1>(test) == 8);

  constexpr fcppt::array::object<int,1U> const c1{1};
  static_assert(fcppt::array::get<0>(c1) == 1);

  fcppt::array::object<int,1> test2{c1};
  fcppt::array::get<0>(test2) = 10;
  CHECK(fcppt::array::get<0>(test2) == 10);
}

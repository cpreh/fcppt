//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/push_back.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("array::push_back", "[array]")
{
  CHECK(
      fcppt::array::push_back(fcppt::array::object<int, 3>{1, 2, 3}, 4) ==
      fcppt::array::object<int, 4>{1, 2, 3, 4});
}

TEST_CASE("array::push_back move", "[array]")
{
  using int_movable = fcppt::catch_::movable<int>;

  CHECK(
      fcppt::array::push_back(
          fcppt::array::object<int_movable, 1>{int_movable{1}}, int_movable{2}) ==
      fcppt::array::object<int_movable, 2>{int_movable{1}, int_movable{2}});
}

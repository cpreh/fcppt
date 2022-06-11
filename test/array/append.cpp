//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/append.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("array::append", "[array]")
{
  CHECK(
      fcppt::array::append(
          fcppt::array::object<int, 2>{1, 2}, fcppt::array::object<int, 3>{3, 4, 5}) ==
      fcppt::array::object<int, 5>{1, 2, 3, 4, 5});
}

TEST_CASE("array::append move", "[array]")
{
  using int_movable = fcppt::catch_::movable<int>;

  CHECK(
      fcppt::array::append(
          fcppt::array::object<int_movable, 2>{int_movable{1}, int_movable{2}},
          fcppt::array::object<int_movable, 3>{int_movable{3}, int_movable{4}, int_movable{5}}) ==
      fcppt::array::object<int_movable, 5>{
          int_movable{1}, int_movable{2}, int_movable{3}, int_movable{4}, int_movable{5}});
}

FCPPT_CATCH_END

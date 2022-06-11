//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/static_row.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::grid::static_row", "[container],[grid]")
{
  using int2_grid = fcppt::container::grid::object<int, 2>;

  int2_grid const grid{
      fcppt::container::grid::static_row(1, 2), fcppt::container::grid::static_row(3, 4)};

  CHECK(grid.get_unsafe(int2_grid::pos(0U, 0U)) == 1);

  CHECK(grid.get_unsafe(int2_grid::pos(1U, 0U)) == 2);

  CHECK(grid.get_unsafe(int2_grid::pos(0U, 1U)) == 3);

  CHECK(grid.get_unsafe(int2_grid::pos(1U, 1U)) == 4);
}

TEST_CASE("container::grid::static_row move", "[container],[grid]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using int2_grid = fcppt::container::grid::object<int_movable, 2>;

  int2_grid const grid{
      fcppt::container::grid::static_row(int_movable(1), int_movable(2)),
      fcppt::container::grid::static_row(int_movable(3), int_movable(4))};

  CHECK(grid.get_unsafe(int2_grid::pos(0U, 0U)) == int_movable(1));

  CHECK(grid.get_unsafe(int2_grid::pos(1U, 0U)) == int_movable(2));

  CHECK(grid.get_unsafe(int2_grid::pos(0U, 1U)) == int_movable(3));

  CHECK(grid.get_unsafe(int2_grid::pos(1U, 1U)) == int_movable(4));
}

FCPPT_CATCH_END

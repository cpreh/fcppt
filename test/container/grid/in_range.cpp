//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/grid/in_range.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::grid::in_range", "[container],[grid]")
{
  using int2_grid = fcppt::container::grid::object<int, 2>;

  int2_grid const test(int2_grid::dim(3U, 4U), 0);

  using pos = int2_grid::pos;

  CHECK(fcppt::container::grid::in_range(test, pos(2U, 2U)));

  CHECK_FALSE(fcppt::container::grid::in_range(test, pos(3U, 2U)));

  CHECK_FALSE(fcppt::container::grid::in_range(test, pos(2U, 4U)));
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
using int2_grid = fcppt::container::grid::object<int, 2>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::grid init reference", "[container],[grid]")
{
  int2_grid const test(int2_grid::dim(10U, 20U), 42);

  CHECK(std::count(test.begin(), test.end(), 42) == 200);
}

TEST_CASE("container::grid index 2d", "[container],[grid]")
{
  int2_grid const test(int2_grid::dim(5U, 10U), [](int2_grid::pos const &) {
    static int entry{0};

    return entry++;
  });

  for (auto const y : fcppt::make_int_range_count(test.size().h()))
  {
    for (auto const x : fcppt::make_int_range_count(test.size().w()))
    {
      CHECK(
          test.get_unsafe(int2_grid::pos(x, y)) ==
          fcppt::cast::size<int2_grid::value_type>(fcppt::cast::to_signed(x + y * 5)));
    }
  }
}

TEST_CASE("container::grid index 3d", "[container],[grid]")
{
  using int3_grid = fcppt::container::grid::object<int, 3>;

  int3_grid const test(int3_grid::dim(5U, 10U, 8U), [](int3_grid::pos const &) {
    static int entry{0};

    return entry++;
  });

  for (auto const z : fcppt::make_int_range_count(test.size().d()))
  {
    for (auto const y : fcppt::make_int_range_count(test.size().h()))
    {
      for (auto const x : fcppt::make_int_range_count(test.size().w()))
      {
        CHECK(
            test.get_unsafe(int3_grid::pos(x, y, z)) ==
            fcppt::cast::size<int3_grid::value_type>(
                fcppt::cast::to_signed(x + y * 5 + z * 5 * 10)));
      }
    }
  }
}

TEST_CASE("container::grid const data", "[container],[grid]")
{
  int2_grid const test(int2_grid::dim(5U, 2U), 42);

  CHECK(std::count(test.begin(), test.end(), 42) == 10);
}

TEST_CASE("container::grid::contents", "[container],[grid]")
{
  int2_grid const test(int2_grid::dim(3U, 2U), 0);

  CHECK(test.content() == 6U);
}

TEST_CASE("container::grid move", "[container],[grid]")
{
  int2_grid grid1(int2_grid::dim(2U, 3U), 0);

  grid1.get_unsafe(int2_grid::pos(0U, 0U)) = 1;

  grid1.get_unsafe(int2_grid::pos(1U, 1U)) = 2;

  int2_grid grid2(std::move(grid1));

  REQUIRE(grid2.size() == int2_grid::dim(2U, 3U));

  CHECK(grid2.get_unsafe(int2_grid::pos(0U, 0U)) == 1);

  CHECK(grid2.get_unsafe(int2_grid::pos(1U, 1U)) == 2);

  int2_grid grid3;

  grid3 = std::move(grid2);

  REQUIRE(grid3.size() == int2_grid::dim(2U, 3U));

  CHECK(grid3.get_unsafe(int2_grid::pos(0U, 0U)) == 1);

  CHECK(grid3.get_unsafe(int2_grid::pos(1U, 1U)) == 2);
}

TEST_CASE("container::grid init", "[container],[grid]")
{
  int2_grid const grid(int2_grid::dim(2U, 3U), [](int2_grid::pos const &_pos) {
    return fcppt::cast::size<int>(fcppt::cast::to_signed(_pos.x() * _pos.y()));
  });

  using pos = int2_grid::pos;

  REQUIRE(fcppt::cast::to_signed(grid.content()) == std::distance(grid.begin(), grid.end()));

  CHECK(grid.get_unsafe(pos(0U, 0U)) == 0);

  CHECK(grid.get_unsafe(pos(1U, 2U)) == 2);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

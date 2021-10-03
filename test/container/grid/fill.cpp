//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/fill.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/static_row.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::grid::fill", "[container],[grid]")
{
  using int2_grid = fcppt::container::grid::object<int, 2>;

  int2_grid test(int2_grid::dim(2U, 2U), 0);

  using pos = int2_grid::pos;

  fcppt::container::grid::fill(test, [](pos const &_pos) {
    return fcppt::cast::size<int>(fcppt::cast::to_signed(_pos.x() + _pos.y()));
  });

  CHECK(
      test ==
      int2_grid{
          fcppt::container::grid::static_row(0, 1), fcppt::container::grid::static_row(1, 2)});
}

FCPPT_CATCH_END

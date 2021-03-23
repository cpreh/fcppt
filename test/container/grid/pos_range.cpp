//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::grid pos range", "[container],[grid]")
{
  using pos = fcppt::container::grid::pos<unsigned, 2>;

  using min = fcppt::container::grid::min_from_pos<pos>;

  using sup = fcppt::container::grid::sup_from_pos<pos>;

  CHECK(
      fcppt::container::grid::make_pos_range_start_end(
          min{fcppt::math::vector::null<pos>()}, sup{pos(3U, 2U)})
          .size() == 6U);

  CHECK(
      fcppt::container::grid::make_pos_range_start_end(min{pos(3U, 2U)}, sup{pos(3U, 1U)}).size() ==
      0U);
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/contains.hpp>
#include <fcppt/container/grid/moore_neighbor_array.hpp>
#include <fcppt/container/grid/moore_neighbors.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
using pos = fcppt::container::grid::pos<unsigned, 2>;

using array = fcppt::container::grid::moore_neighbor_array<pos>;

bool contains_element(array const &_result, pos const &_pos)
{
  return fcppt::algorithm::contains(_result, _pos);
}

}

TEST_CASE("container::grid::moore_neighbors", "[container],[grid]")
{
  array const result(fcppt::container::grid::moore_neighbors(pos(5U, 7U)));

  CHECK(contains_element(result, pos(4U, 7U)));

  CHECK(contains_element(result, pos(6U, 7U)));

  CHECK(contains_element(result, pos(5U, 6U)));

  CHECK(contains_element(result, pos(5U, 8U)));

  CHECK(contains_element(result, pos(4U, 6U)));

  CHECK(contains_element(result, pos(6U, 6U)));

  CHECK(contains_element(result, pos(4U, 8U)));

  CHECK(contains_element(result, pos(6U, 8U)));
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/contains.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/moore_neighbor_array.hpp>
#include <fcppt/container/grid/moore_neighbors.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
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

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

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

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

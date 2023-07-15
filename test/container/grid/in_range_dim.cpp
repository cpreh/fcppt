//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/in_range_dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::grid::in_range_dim", "[container],[grid]")
{
  using int2_pos = fcppt::container::grid::pos<std::size_t, 2U>;

  using int2_dim = fcppt::container::grid::dim<std::size_t, 2U>;

  int2_dim const test{3U, 4U};

  CHECK(fcppt::container::grid::in_range_dim(test, int2_pos(2U, 2U)));

  CHECK_FALSE(fcppt::container::grid::in_range_dim(test, int2_pos(3U, 2U)));

  CHECK_FALSE(fcppt::container::grid::in_range_dim(test, int2_pos(2U, 4U)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

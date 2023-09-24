//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/grid/comparison.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::grid comparison"
          "[container],[grid]")
{
  using int2_grid = fcppt::container::grid::object<int, 2>;

  int2_grid const test1(int2_grid::dim(5U, 10U), 0);

  int2_grid test2(int2_grid::dim(10U, 2U), 0);

  CHECK(test1 != test2);

  CHECK(test1 < test2);

  CHECK(test1 <= test2);

  CHECK_FALSE(test1 > test2);

  CHECK_FALSE(test1 >= test2);

  test2 = test1;

  CHECK(test1 == test2);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

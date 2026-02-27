//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp> // IWYU pragma: keep
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::dim arithmetic_self", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  using i2_dim = fcppt::math::dim::static_<int, 2>;

  ui2_dim dim(0U, 0U);

  dim += ui2_dim(1U, 2U);

  CHECK(dim == ui2_dim(1U, 2U));

  dim *= 2U;

  CHECK(dim == ui2_dim(2U, 4U));

  i2_dim dimi(1, 2);

  dimi = -dimi;

  CHECK(dimi == i2_dim(-1, -2));
}

TEST_CASE("math::dim arithmetic free", "[math],[dim]")
{
  using i2_dim = fcppt::math::dim::static_<int, 2>;

  CHECK(i2_dim(1, 2) + i2_dim(3, 4) == i2_dim(4, 6));

  CHECK(i2_dim(5, 2) - i2_dim(3, 4) == i2_dim(2, -2));

  CHECK(i2_dim(2, 3) * i2_dim(3, 4) == i2_dim(6, 12));

  CHECK(-i2_dim(2, 3) == i2_dim(-2, -3));

  CHECK(i2_dim(2, 3) * 2 == i2_dim(4, 6));

  CHECK(2 * i2_dim(2, 3) == i2_dim(4, 6));

  CHECK(i2_dim(4, 6) / 2 == fcppt::optional::make(i2_dim(2, 3)));

  CHECK(i2_dim(6, 6) / i2_dim(2, 3) == fcppt::optional::make(i2_dim(3, 2)));

  CHECK((i2_dim(6, 6) / i2_dim(2, 0)) == fcppt::optional::object<i2_dim>{});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/sphere/circle.hpp>
#include <fcppt/math/sphere/comparison.hpp>
#include <fcppt/math/sphere/intersects.hpp>
#include <fcppt/math/sphere/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::sphere::intersects", "[math],[sphere]")
{
  using circle_type = fcppt::math::sphere::circle<float>;

  CHECK(fcppt::math::sphere::intersects(
      circle_type(circle_type::point_type(0.F, 0.F), 1.F),
      circle_type(circle_type::point_type(1.F, 0.F), 1.F)));
}

TEST_CASE("math::sphere comparison", "[math],[sphere]")
{
  using circle_type = fcppt::math::sphere::circle<int>;

  CHECK(
      circle_type(circle_type::point_type(1, 3), 2) ==
      circle_type(circle_type::point_type(1, 3), 2));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

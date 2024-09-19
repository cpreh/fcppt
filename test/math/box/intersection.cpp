//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/intersection.hpp>
#include <fcppt/math/box/null.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::box::intersection", "[math],[box]")
{
  using box_i2 = fcppt::math::box::object<int, 2>;

  box_i2 const box1(box_i2::vector(1, 1), box_i2::dim(2, 2));

  box_i2 const box2(box_i2::vector(0, 0), box_i2::dim(4, 4));

  box_i2 const box3(box_i2::vector(2, 2), box_i2::dim(2, 2));

  box_i2 const box4(box_i2::vector(5, 5), box_i2::dim(1, 1));

  box_i2 const intersection1(fcppt::math::box::intersection(box1, box2));

  box_i2 const intersection2(fcppt::math::box::intersection(box1, box3));

  box_i2 const intersection3(fcppt::math::box::intersection(box1, box4));

  CHECK(intersection1 == box1);

  box_i2 const result2(box_i2::vector(2, 2), box_i2::dim(1, 1));

  CHECK(intersection2 == result2);

  CHECK(intersection3 == fcppt::math::box::null<box_i2>());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

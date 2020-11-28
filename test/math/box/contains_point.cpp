//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/box/contains_point.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::box::contains_point", "[math],[box]")
{
  using box2 = fcppt::math::box::rect<int>;

  box2 const outer{box2::vector{0, 0}, box2::dim{5, 5}};

  CHECK(fcppt::math::box::contains_point(outer, box2::vector{1, 1}));

  CHECK_FALSE(fcppt::math::box::contains_point(outer, box2::vector{-1, 1}));

  CHECK_FALSE(fcppt::math::box::contains_point(outer, box2::vector{6, 5}));
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/rad_to_deg.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::rad_to_deg", "[math]")
{
  using Catch::literals::operator""_a;

  CHECK(fcppt::math::rad_to_deg(0.F) == 0.0_a);

  CHECK(fcppt::math::rad_to_deg(3.14159F) == 180.0_a);
}

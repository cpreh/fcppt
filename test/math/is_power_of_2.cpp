//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::is_power_of_2", "[math]")
{
  CHECK_FALSE(fcppt::math::is_power_of_2(0U));

  CHECK(fcppt::math::is_power_of_2(1U));

  CHECK(fcppt::math::is_power_of_2(2U));

  CHECK(fcppt::math::is_power_of_2(4U));

  CHECK_FALSE(fcppt::math::is_power_of_2(3U));

  CHECK_FALSE(fcppt::math::is_power_of_2(5U));
}

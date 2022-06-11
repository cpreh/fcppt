//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::power_of_2", "[math]")
{
  static_assert(fcppt::math::power_of_2<unsigned>(2U) == 4U);
  CHECK(fcppt::math::power_of_2<unsigned>(2U) == 4U);
  static_assert(fcppt::math::power_of_2<std::uint8_t>(2U) == std::uint8_t{4});
  CHECK(fcppt::math::power_of_2<std::uint8_t>(2U) == std::uint8_t{4});
}

FCPPT_CATCH_END

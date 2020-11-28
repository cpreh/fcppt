//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::vector::at", "[math],[vector]")
{
  using vector2 = fcppt::math::vector::static_<int, 2>;

  vector2 const vector_c(1, 2);

  CHECK(fcppt::math::vector::at<0>(vector_c) == 1);

  CHECK(fcppt::math::vector::at<1>(vector_c) == 2);

  vector2 vector_m(1, 2);

  fcppt::math::vector::at<1>(vector_m) = 3;

  CHECK(fcppt::math::vector::at<1>(vector_m) == 3);
}

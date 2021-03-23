//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/matrix/at_r.hpp>
#include <fcppt/math/matrix/object.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::matrix::at_r", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<int, 2, 2>;

  matrix_type const mat(fcppt::math::matrix::row(-3, 2), fcppt::math::matrix::row(-1, 0));

  {
    auto const view(fcppt::math::matrix::at_r<0>(mat));

    CHECK(fcppt::math::vector::at<0>(view) == -3);
  }

  {
    auto const view(fcppt::math::matrix::at_r<0>(mat));

    CHECK(fcppt::math::vector::at<1>(view) == 2);
  }

  {
    auto const view(fcppt::math::matrix::at_r<1>(mat));

    CHECK(fcppt::math::vector::at<0>(view) == -1);
  }

  {
    auto const view(fcppt::math::matrix::at_r<1>(mat));

    CHECK(fcppt::math::vector::at<1>(view) == 0);
  }
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_signed_fun.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::matrix::structure_cast", "[math],[matrix]")
{
  using ui2_matrix = fcppt::math::matrix::static_<unsigned, 2, 2>;

  using i2_matrix = fcppt::math::matrix::static_<int, 2, 2>;

  CHECK(
      i2_matrix{fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)} ==
      fcppt::math::matrix::structure_cast<i2_matrix, fcppt::cast::to_signed_fun>(
          ui2_matrix(fcppt::math::matrix::row(1U, 2U), fcppt::math::matrix::row(3U, 4U))));
}

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/transpose.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::matrix::transpose", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<int, 2, 3>;

  using transposed_matrix_type = fcppt::math::matrix::static_<int, 3, 2>;

  CHECK(
      fcppt::math::matrix::transpose(
          matrix_type(fcppt::math::matrix::row(1, 2, 3), fcppt::math::matrix::row(4, 5, 6))) ==
      transposed_matrix_type(
          fcppt::math::matrix::row(1, 4),
          fcppt::math::matrix::row(2, 5),
          fcppt::math::matrix::row(3, 6)));
}

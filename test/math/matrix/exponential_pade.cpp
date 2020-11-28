//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/exponential_pade.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::matrix::exponential_pade", "[math[,[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<double, 3, 3>;

  double const epsilon{0.01};

  CHECK(fcppt::math::matrix::componentwise_equal(
      fcppt::math::matrix::exponential_pade(matrix_type{
          fcppt::math::matrix::row(2.0, -1.0, 1.0),
          fcppt::math::matrix::row(0.0, 3.0, -1.0),
          fcppt::math::matrix::row(2.0, 1.0, 3.0)}),
      matrix_type(
          fcppt::math::matrix::row(23.6045, -7.38906, 23.6045),
          fcppt::math::matrix::row(-16.2155, 14.7781, -23.6045),
          fcppt::math::matrix::row(30.9936, 7.38906, 30.9936)),
      epsilon));
}

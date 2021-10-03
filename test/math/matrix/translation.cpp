//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::matrix::translation", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<int, 4, 4>;

  matrix_type const trans(fcppt::math::matrix::translation(5, 3, 42));

  CHECK(
      trans == matrix_type(
                   fcppt::math::matrix::row(1, 0, 0, 5),
                   fcppt::math::matrix::row(0, 1, 0, 3),
                   fcppt::math::matrix::row(0, 0, 1, 42),
                   fcppt::math::matrix::row(0, 0, 0, 1)));

  using vector_type = fcppt::math::vector::static_<int, 4>;

  vector_type const vec(1, 2, 3, 1);

  CHECK(trans * vec == vector_type(6, 5, 45, 1));
}

FCPPT_CATCH_END

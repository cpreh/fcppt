//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
using mat2 = fcppt::math::matrix::static_<int, 2, 2>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix arithmetic self", "[math],[matrix]")
{
  {
    mat2 left{fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)};

    left += mat2{fcppt::math::matrix::row(5, 6), fcppt::math::matrix::row(7, 8)};

    CHECK(left == mat2(fcppt::math::matrix::row(6, 8), fcppt::math::matrix::row(10, 12)));
  }

  {
    mat2 left{fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)};

    left -= mat2{fcppt::math::matrix::row(2, 4), fcppt::math::matrix::row(1, 2)};

    CHECK(left == mat2(fcppt::math::matrix::row(-1, -2), fcppt::math::matrix::row(2, 2)));
  }

  {
    mat2 left{fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)};

    left *= 2;

    CHECK(left == mat2(fcppt::math::matrix::row(2, 4), fcppt::math::matrix::row(6, 8)));
  }
}

TEST_CASE("math::matrix arithmetic free", "[math],[matrix]")
{
  CHECK(
      mat2(fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)) +
          mat2(fcppt::math::matrix::row(5, 6), fcppt::math::matrix::row(7, 8)) ==
      mat2(fcppt::math::matrix::row(6, 8), fcppt::math::matrix::row(10, 12)));

  CHECK(
      mat2(fcppt::math::matrix::row(5, 6), fcppt::math::matrix::row(7, 8)) -
          mat2(fcppt::math::matrix::row(4, 3), fcppt::math::matrix::row(2, 1)) ==
      mat2(fcppt::math::matrix::row(1, 3), fcppt::math::matrix::row(5, 7)));

  CHECK(
      mat2(fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)) * 2 ==
      mat2(fcppt::math::matrix::row(2, 4), fcppt::math::matrix::row(6, 8)));

  CHECK(
      2 * mat2(fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)) ==
      mat2(fcppt::math::matrix::row(2, 4), fcppt::math::matrix::row(6, 8)));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

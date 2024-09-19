//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::determinant", "[math],[matrix]")
{
  using large_matrix_type = fcppt::math::matrix::static_<int, 3, 3>;

  using small_matrix_type = fcppt::math::matrix::static_<int, 2, 2>;

  CHECK(
      fcppt::math::matrix::determinant(large_matrix_type(
          fcppt::math::matrix::row(1, 2, 3),
          fcppt::math::matrix::row(4, 5, 6),
          fcppt::math::matrix::row(7, 8, 9))) == 0);

  CHECK(
      fcppt::math::matrix::determinant(small_matrix_type(
          fcppt::math::matrix::row(-3, -5), fcppt::math::matrix::row(-1, -2))) == 1);

  CHECK(fcppt::math::matrix::determinant(fcppt::math::matrix::identity<large_matrix_type>()) == 1);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

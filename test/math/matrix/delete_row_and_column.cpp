//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::delete_row_and_column", "[math],[matrix]")
{
  using large_matrix_type = fcppt::math::matrix::static_<int, 4, 3>;

  using small_matrix_type = fcppt::math::matrix::static_<int, 3, 2>;

  large_matrix_type const matrix(
      fcppt::math::matrix::row(1, 2, 3),
      fcppt::math::matrix::row(4, 5, 6),
      fcppt::math::matrix::row(7, 8, 9),
      fcppt::math::matrix::row(10, 11, 12));

  CHECK(
      fcppt::math::matrix::delete_row_and_column<2, 1>(matrix) ==
      small_matrix_type(
          fcppt::math::matrix::row(1, 3),
          fcppt::math::matrix::row(4, 6),
          fcppt::math::matrix::row(10, 12)));

  CHECK(
      fcppt::math::matrix::delete_row_and_column<0, 0>(matrix) ==
      small_matrix_type(
          fcppt::math::matrix::row(5, 6),
          fcppt::math::matrix::row(8, 9),
          fcppt::math::matrix::row(11, 12)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

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

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::multiply", "[math],[matrix]")
{
  using mat3 = fcppt::math::matrix::static_<int, 3, 3>;

  mat3 const left(
      fcppt::math::matrix::row(1, 2, 3),
      fcppt::math::matrix::row(4, 5, 6),
      fcppt::math::matrix::row(7, 8, 9));

  mat3 const right(
      fcppt::math::matrix::row(10, 11, 12),
      fcppt::math::matrix::row(13, 14, 15),
      fcppt::math::matrix::row(16, 17, 18));

  mat3 const result(left * right);

  CHECK(
      result == mat3(
                    fcppt::math::matrix::row(84, 90, 96),
                    fcppt::math::matrix::row(201, 216, 231),
                    fcppt::math::matrix::row(318, 342, 366)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/at_r.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix view", "[math],[matrix]")
{
  using value_type = int;

  constexpr fcppt::math::size_type const size{3U};

  using matrix_type = fcppt::math::matrix::static_<value_type, size, size>;

  using vector_type = fcppt::math::vector::static_<value_type, size>;

  matrix_type const matrix(
      fcppt::math::matrix::row(-3, 2, -5),
      fcppt::math::matrix::row(-1, 0, -2),
      fcppt::math::matrix::row(3, -4, 1));

  CHECK(fcppt::math::matrix::at_r<0>(matrix) == vector_type(-3, 2, -5));

  vector_type vec(fcppt::math::matrix::at_r<0>(matrix));

  vec = fcppt::math::matrix::at_r<1>(matrix);

  CHECK(vec == vector_type(-1, 0, -2));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

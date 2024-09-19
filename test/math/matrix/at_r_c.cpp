//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/at_r_c.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::at_r_c", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<int, 2, 2>;

  matrix_type const mat(fcppt::math::matrix::row(-3, 2), fcppt::math::matrix::row(-1, 0));

  CHECK(fcppt::math::matrix::at_r_c<0, 0>(mat) == -3);

  CHECK(fcppt::math::matrix::at_r_c<0, 1>(mat) == 2);

  CHECK(fcppt::math::matrix::at_r_c<1, 0>(mat) == -1);

  CHECK(fcppt::math::matrix::at_r_c<1, 1>(mat) == 0);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

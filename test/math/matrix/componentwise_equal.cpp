//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::componentwise_equal", "[math],[matrix]")
{
  using matrix12 = fcppt::math::matrix::static_<float,1,2>;

  float const epsilon{0.00001F};

  CHECK(fcppt::math::matrix::componentwise_equal(
      matrix12{fcppt::math::matrix::row(1.F, 2.F)},
      matrix12{fcppt::math::matrix::row(1.F, 2.F)},
      epsilon));

  CHECK_FALSE(fcppt::math::matrix::componentwise_equal(
      matrix12{fcppt::math::matrix::row(1.F, 2.F)},
      matrix12{fcppt::math::matrix::row(1.1F, 2.F)},
      epsilon));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

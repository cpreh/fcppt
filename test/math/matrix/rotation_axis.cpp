//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/rotation_axis.hpp>
#include <fcppt/math/matrix/rotation_x.hpp>
#include <fcppt/math/matrix/rotation_y.hpp>
#include <fcppt/math/matrix/rotation_z.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <numbers>
#include <fcppt/config/external_end.hpp>

namespace
{
float const epsilon{0.001F};

template <typename Matrix>
bool compare_matrices(Matrix const &_m1, Matrix const &_m2)
{
  return fcppt::math::matrix::componentwise_equal(_m1, _m2, epsilon);
}

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix rotation_axis", "[math],[matrix]")
{
  using matrix_type = fcppt::math::matrix::static_<float, 4, 4>;

  using vector_rotation_type = fcppt::math::vector::static_<float, 3>;

  matrix_type const trans(fcppt::math::matrix::rotation_axis(
      std::numbers::pi_v<float>, vector_rotation_type(1.F, 0.F, 0.F)));

  using vector_type = fcppt::math::vector::static_<float, 4>;

  vector_type const vec(0.F, 1.F, 0.F, 1.F);

  CHECK(fcppt::math::vector::componentwise_equal(
      trans * vec, vector_type(0.F, -1.F, 0.F, 1.F), epsilon));

  CHECK(::compare_matrices(
      fcppt::math::matrix::rotation_axis(0.F, vector_rotation_type(0.F, 0.F, 0.F)),
      fcppt::math::matrix::identity<matrix_type>()));

  float const angle{std::numbers::pi_v<float> / 2.F};

  CHECK(::compare_matrices(
      fcppt::math::matrix::rotation_axis(angle, vector_rotation_type(1.F, 0.F, 0.F)),
      fcppt::math::matrix::rotation_x(angle)));

  CHECK(::compare_matrices(
      fcppt::math::matrix::rotation_axis(angle, vector_rotation_type(0.F, 1.F, 0.F)),
      fcppt::math::matrix::rotation_y(angle)));

  CHECK(::compare_matrices(
      fcppt::math::matrix::rotation_axis(angle, vector_rotation_type(0.F, 0.F, 1.F)),
      fcppt::math::matrix::rotation_z(angle)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

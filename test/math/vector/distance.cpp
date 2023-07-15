//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/distance.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector::distance", "[math],[vector]")
{
  using float2_vector = fcppt::math::vector::static_<float, 2>;

  CHECK_THAT(
      std::abs(
          fcppt::math::vector::distance(float2_vector(1.F, 2.F), float2_vector(3.F, 4.F)) - 2.8F),
      Catch::Matchers::WithinAbs(0., 0.1));

  using uint2_vector = fcppt::math::vector::static_<unsigned, 2>;

  CHECK_THAT(
      std::abs(
          fcppt::math::vector::distance<float>(uint2_vector(1U, 2U), uint2_vector(3U, 4U)) - 2.8F),
      Catch::Matchers::WithinAbs(0., 0.1));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

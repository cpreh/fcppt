//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector arithmetic self", "[math],[vector]")
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  using i2_vector = fcppt::math::vector::static_<int, 2>;

  ui2_vector vec(0U, 0U);

  vec += ui2_vector(1U, 2U);

  REQUIRE(vec == ui2_vector(1U, 2U));

  vec *= 2U;

  REQUIRE(vec == ui2_vector(2U, 4U));

  i2_vector veci(1, 2);

  veci = -veci;

  CHECK(veci == i2_vector(-1, -2));
}

TEST_CASE("math::vector arithmetic free", "[math],[vector]")
{
  using i2_vector = fcppt::math::vector::static_<int, 2>;

  CHECK(i2_vector(1, 2) + i2_vector(3, 4) == i2_vector(4, 6));

  CHECK(i2_vector(5, 2) - i2_vector(3, 4) == i2_vector(2, -2));

  CHECK(i2_vector(2, 3) * i2_vector(3, 4) == i2_vector(6, 12));

  CHECK(-i2_vector(2, 3) == i2_vector(-2, -3));

  CHECK(2 * i2_vector(2, 3) == i2_vector(4, 6));

  CHECK(i2_vector(2, 3) * 2 == i2_vector(4, 6));

  CHECK(i2_vector(4, 6) / 2 == fcppt::optional::make(i2_vector(2, 3)));

  CHECK(i2_vector(6, 6) / i2_vector(2, 3) == fcppt::optional::make(i2_vector(3, 2)));

  CHECK((i2_vector(6, 6) / i2_vector(2, 0)) == fcppt::optional::object<i2_vector>{});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

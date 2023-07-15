//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <numbers>
#include <fcppt/config/external_end.hpp>

namespace
{
using scalar = float;

bool almost_equal(
    fcppt::optional::object<scalar> const _f1, fcppt::optional::object<scalar> const _f2)
{
  return fcppt::optional::from(
      fcppt::optional::apply(
          [](scalar const _x1, scalar const _x2) {
            return fcppt::math::diff(_x1, _x2) < fcppt::literal<scalar>(0.01F);
          },
          _f1,
          _f2),
      fcppt::const_(false));
}

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector::atan2", "[math],[vector]")
{
  using float2_vec = fcppt::math::vector::static_<scalar, 2>;

  scalar const pi{std::numbers::pi_v<scalar>};

  CHECK_FALSE(fcppt::math::vector::atan2(float2_vec{0.F, 0.F}).has_value());

  CHECK(almost_equal(fcppt::math::vector::atan2(float2_vec{1.F, 0.F}), fcppt::optional::make(0.F)));

  CHECK(almost_equal(fcppt::math::vector::atan2(float2_vec{-1.F, 0.F}), fcppt::optional::make(pi)));

  CHECK(almost_equal(
      fcppt::math::vector::atan2(float2_vec{0.F, 1.F}), fcppt::optional::make(pi / 2.F)));

  CHECK(almost_equal(
      fcppt::math::vector::atan2(float2_vec{0.F, -1.F}), fcppt::optional::make(-pi / 2.F)));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

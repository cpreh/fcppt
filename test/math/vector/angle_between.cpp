//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/vector/angle_between.hpp>
#include <fcppt/math/vector/angle_between_cast.hpp>
#include <fcppt/math/vector/signed_angle_between.hpp>
#include <fcppt/math/vector/signed_angle_between_cast.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <limits>
#include <numbers>
#include <fcppt/config/external_end.hpp>

namespace
{
using real = float;

real const epsilon{std::numeric_limits<real>::epsilon()};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)

real const half_pi{std::numbers::pi_v<real> / fcppt::literal<real>(2.F)};

FCPPT_PP_POP_WARNING

inline bool
compare(fcppt::optional::object<real> const _o1, fcppt::optional::object<real> const _o2)
{
  return fcppt::optional::from(
      fcppt::optional::apply(
          [](real const _t1, real const _t2) { return fcppt::math::diff(_t1, _t2) < epsilon; },
          _o1,
          _o2),
      fcppt::const_(true));
}

using uivector2 = fcppt::math::vector::static_<unsigned, 2>;

using fvector2 = fcppt::math::vector::static_<real, 2>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector::angle_between", "[math],[vector]")
{
  CHECK(::compare(
      fcppt::math::vector::angle_between(fvector2{1.F, 0.F}, fvector2{0.F, 1.F}),
      fcppt::optional::make(half_pi)));

  CHECK_FALSE(
      fcppt::math::vector::angle_between(fvector2{1.F, 0.F}, fvector2{0.F, 0.F}).has_value());
}

TEST_CASE("math::vector::angle_between_cast", "[math],[vector]")
{
  CHECK(::compare(
      fcppt::math::vector::angle_between_cast<real>(uivector2{1U, 0U}, uivector2{0U, 1U}),
      fcppt::optional::make(half_pi)));
}

TEST_CASE("math::vector::signed_angle_between", "[math],[vector]")
{
  CHECK(::compare(
      fcppt::math::vector::signed_angle_between(fvector2{2.F, 1.F}, fvector2{2.F, 2.F}),
      fcppt::optional::make(half_pi)));
}

TEST_CASE("math::vector::signed_angle_between_cast", "[math],[vector]")
{
  CHECK(::compare(
      fcppt::math::vector::signed_angle_between_cast<real>(uivector2{2U, 1U}, uivector2{2U, 2U}),
      fcppt::optional::make(half_pi)));

  CHECK_FALSE(
      fcppt::math::vector::signed_angle_between_cast<real>(uivector2{2U, 2U}, uivector2{2U, 2U})
          .has_value());
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

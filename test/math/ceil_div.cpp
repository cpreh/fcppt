//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/ceil_div.hpp>
#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::ceil_div", "[math]")
{
  CHECK(fcppt::math::ceil_div(0U, 1U) == fcppt::optional::make(0U));

  CHECK(fcppt::math::ceil_div(1U, 1U) == fcppt::optional::make(1U));

  CHECK(fcppt::math::ceil_div(5U, 3U) == fcppt::optional::make(2U));

  CHECK(fcppt::math::ceil_div(6U, 3U) == fcppt::optional::make(2U));

  CHECK(fcppt::math::ceil_div(2U, 0U) == fcppt::optional::object<unsigned>{});
}

TEST_CASE("math::ceil_div_signed", "[math]")
{
  CHECK(fcppt::math::ceil_div_signed(-3, 2) == fcppt::optional::make(-1));

  CHECK(fcppt::math::ceil_div_signed(5, 3) == fcppt::optional::make(2));

  CHECK(fcppt::math::ceil_div_signed(5, 0) == fcppt::optional::object<int>{});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/interval_distance.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::interval_distance", "[math]")
{
  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(0, 2), fcppt::tuple::make(3, 10)) == 1);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(3, 10), fcppt::tuple::make(0, 2)) == 1);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(2, 5), fcppt::tuple::make(4, 7)) == -1);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(4, 7), fcppt::tuple::make(2, 5)) == -1);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(4, 6), fcppt::tuple::make(6, 7)) == 0);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(6, 7), fcppt::tuple::make(4, 6)) == 0);

  CHECK(
      fcppt::math::interval_distance(
          fcppt::tuple::make(3, 4), fcppt::tuple::make(0, 10)) == -3);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

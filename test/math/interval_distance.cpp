//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/interval_distance.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

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

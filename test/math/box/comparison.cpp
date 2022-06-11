//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::box comparison", "[math],[box]")
{
  using box_type = fcppt::math::box::object<int, 2>;

  CHECK(
      box_type(box_type::vector(1, 2), box_type::dim(3, 4)) ==
      box_type(box_type::vector(1, 2), box_type::dim(3, 4)));

  CHECK(
      box_type(box_type::vector(1, 2), box_type::dim(3, 4)) !=
      box_type(box_type::vector(5, 2), box_type::dim(3, 4)));

  CHECK(
      box_type(box_type::vector(1, 2), box_type::dim(3, 4)) <
      box_type(box_type::vector(5, 2), box_type::dim(3, 4)));
}

FCPPT_CATCH_END

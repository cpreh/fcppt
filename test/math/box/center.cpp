//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/box/center.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::box::center", "[math],[box]")
{
  using box_type = fcppt::math::box::object<int, 3>;

  CHECK(
      fcppt::math::box::center(box_type{box_type::vector{10, 12, 14}, box_type::dim{24, 26, 4}}) ==
      box_type::vector{22, 25, 16});
}

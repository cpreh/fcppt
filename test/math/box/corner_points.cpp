//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object.hpp>
#include <fcppt/math/box/corner_points.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::box::corner_points", "[math],[box]")
{
  using box_type = fcppt::math::box::object<int, 2>;

  CHECK(
      fcppt::math::box::corner_points(box_type{box_type::vector{10, 12}, box_type::dim{24, 26}}) ==
      fcppt::array::object<box_type::vector, 4>{
          box_type::vector(10, 12),
          box_type::vector(34, 12),
          box_type::vector(10, 38),
          box_type::vector(34, 38)});
}

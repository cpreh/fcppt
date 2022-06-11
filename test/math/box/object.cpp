//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::box::sobject", "[math],[box]")
{
  using box_type = fcppt::math::box::object<int, 3>;
  using vector = box_type::vector;
  using dim = box_type::dim;

  box_type const box1{vector{10, 12, 14}, dim{24, 26, 28}};

  CHECK(box1.pos() == vector{10, 12, 14});
  CHECK(box1.size() == dim{24, 26, 28});
  CHECK(box1.min() == vector{10, 12, 14});
  CHECK(box1.max() == vector{34, 38, 42});
  CHECK(box1.left() == 10);
  CHECK(box1.right() == 34);
  CHECK(box1.top() == 12);
  CHECK(box1.bottom() == 38);
  CHECK(box1.front() == 14);
  CHECK(box1.back() == 42);

  CHECK(box1 == box_type{box_type::min_t{vector{10, 12, 14}}, box_type::max_t{vector{34, 38, 42}}});
}

FCPPT_CATCH_END

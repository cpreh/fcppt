//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::vector::static", "[math],[vector]")
{
  using int2_vector = fcppt::math::vector::static_<int, 2>;

  int2_vector const vec{0, 1};

  CHECK(vec.x() == 0);

  CHECK(vec.y() == 1);
}

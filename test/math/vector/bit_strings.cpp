//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector::bit_strings", "[math],[vector]")
{
  using vector2 = fcppt::math::vector::static_<int, 2>;

  using vector3 = fcppt::math::vector::static_<int, 3>;

  CHECK(
      fcppt::math::vector::bit_strings<int, 2>() ==
      fcppt::array::object<vector2, 4>{vector2(0, 0), vector2(1, 0), vector2(0, 1), vector2(1, 1)});

  CHECK(
      fcppt::math::vector::bit_strings<int, 3>() == fcppt::array::object<vector3, 8>{
                                                        vector3(0, 0, 0),
                                                        vector3(1, 0, 0),
                                                        vector3(0, 1, 0),
                                                        vector3(1, 1, 0),
                                                        vector3(0, 0, 1),
                                                        vector3(1, 0, 1),
                                                        vector3(0, 1, 1),
                                                        vector3(1, 1, 1)});
}

FCPPT_CATCH_END

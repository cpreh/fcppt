//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/binary_map.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector::binary_map", "[math],[vector]")
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  using i2_vector = fcppt::math::vector::static_<int, 2>;

  CHECK(
      fcppt::math::vector::binary_map(
          ui2_vector{10U, 20U}, i2_vector{3, 5}, [](unsigned const _val1, int const _val2) {
            return fcppt::cast::to_signed(_val1) + _val2;
          }) == i2_vector(13, 25));
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/map.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector::map", "[math],[vector]")
{
  using i2_vector = fcppt::math::vector::static_<int, 2>;

  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  CHECK(fcppt::math::vector::map(ui2_vector{10U, 20U}, [](unsigned const _val) {
          return fcppt::cast::to_signed(_val);
        }) == i2_vector(10, 20));
}

FCPPT_CATCH_END

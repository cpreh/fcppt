//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/binary_map.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::dim::binary_map", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  using i2_dim = fcppt::math::dim::static_<int, 2>;

  CHECK(
      fcppt::math::dim::binary_map(
          ui2_dim{10U, 20U}, i2_dim{3, 5}, [](unsigned const _val1, int const _val2) {
            return fcppt::cast::to_signed(_val1) + _val2;
          }) == i2_dim(13, 25));
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/narrow_cast.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::dim::narrow_cast", "[math],[dim]")
{
  using i2_dim = fcppt::math::dim::static_<int, 2>;

  using i3_dim = fcppt::math::dim::static_<int, 3>;

  CHECK(i2_dim(1, 2) == fcppt::math::dim::narrow_cast<i2_dim>(i3_dim(1, 2, 3)));
}

FCPPT_CATCH_END

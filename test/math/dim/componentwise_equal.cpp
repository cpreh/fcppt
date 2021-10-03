//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/componentwise_equal.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::dim::componentwise_equal", "[math],[dim]")
{
  using f2_dim = fcppt::math::dim::static_<float, 2>;

  float const epsilon(0.00001F);

  CHECK(fcppt::math::dim::componentwise_equal(f2_dim(1.F, 2.F), f2_dim(1.F, 2.F), epsilon));

  CHECK_FALSE(fcppt::math::dim::componentwise_equal(f2_dim(1.F, 2.F), f2_dim(1.1F, 2.F), epsilon));
}

FCPPT_CATCH_END

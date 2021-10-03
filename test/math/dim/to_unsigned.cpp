//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::dim::to_unsigned", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  using i2_dim = fcppt::math::dim::static_<int, 2>;

  CHECK(fcppt::math::dim::to_unsigned(i2_dim{1, 2}) == ui2_dim(1U, 2U));
}

FCPPT_CATCH_END

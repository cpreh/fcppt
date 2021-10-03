//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/is_quadratic.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::dim::is_quadratic", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  CHECK_FALSE(fcppt::math::dim::is_quadratic(ui2_dim{10U, 20U}));

  CHECK(fcppt::math::dim::is_quadratic(ui2_dim{10U, 10U}));
}

FCPPT_CATCH_END

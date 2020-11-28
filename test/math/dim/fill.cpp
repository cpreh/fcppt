//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/fill.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::dim::fill", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  CHECK(ui2_dim(42U, 42U) == fcppt::math::dim::fill<ui2_dim>(42U));
}

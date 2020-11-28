//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/fill.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::vector::fill", "[math],[vector]")
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  CHECK(fcppt::math::vector::fill<ui2_vector>(42U) == ui2_vector{42U, 42U});
}

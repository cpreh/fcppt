//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector dim", "[math],[vector]")
{
  using i2_vector = fcppt::math::vector::static_<int, 2>;

  using i2_dim = fcppt::math::dim::static_<int, 2>;

  CHECK(i2_vector(1, 2) + i2_dim(3, 4) == i2_vector(4, 6));

  CHECK(i2_vector(5, 2) - i2_dim(3, 4) == i2_vector(2, -2));

  CHECK(i2_vector(2, 3) * i2_dim(3, 4) == i2_vector(6, 12));

  CHECK(i2_vector(6, 6) / i2_dim(2, 3) == fcppt::optional::make(i2_vector(3, 2)));

  CHECK((i2_vector(6, 6) / i2_dim(2, 0)) == fcppt::optional::object<i2_vector>{});
}

FCPPT_CATCH_END

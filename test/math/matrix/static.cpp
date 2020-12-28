//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::matrix::static", "[math],[matrix]")
{
  using matrix22 = fcppt::math::matrix::static_<int,2,2>;

  matrix22 const no_init{fcppt::no_init{}};
  CHECK(no_init.storage().data() != nullptr);
}

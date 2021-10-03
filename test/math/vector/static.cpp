//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector::static", "[math],[vector]")
{
  using int2_vector = fcppt::math::vector::static_<int, 2>;

  int2_vector const vec{0, 1};

  CHECK(vec.x() == 0);

  CHECK(vec.y() == 1);
}

TEST_CASE("math::vector::static no_init", "[math],[vector]")
{
  using int2_vector = fcppt::math::vector::static_<int, 2>;

  int2_vector const vec{fcppt::no_init{}};

  CHECK(vec.storage().data() != nullptr);
}

TEST_CASE("math::vector::static move", "[math],[vector]")
{
  using int_movable = fcppt::catch_::movable<int>;
  using int2_vector = fcppt::math::vector::static_<int_movable, 2>;

  int2_vector const vec{int_movable{0}, int_movable{1}};

  CHECK(vec.x().value() == 0);
  CHECK(vec.y().value() == 1);
}

FCPPT_CATCH_END

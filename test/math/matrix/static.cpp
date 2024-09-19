//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::matrix::static", "[math],[matrix]")
{
  using matrix22 = fcppt::math::matrix::static_<int,2,2>;

  matrix22 const mat{fcppt::math::matrix::row(1, 2), fcppt::math::matrix::row(3, 4)};

  CHECK(mat.m00() == 1);
  CHECK(mat.m01() == 2);
  CHECK(mat.m10() == 3);
  CHECK(mat.m11() == 4);
}

TEST_CASE("math::matrix::static move", "[math],[matrix]")
{
  using int_movable = fcppt::catch_::movable<int>;
  using matrix22 = fcppt::math::matrix::static_<int_movable,2,2>;

  matrix22 const mat{
      fcppt::math::matrix::row(int_movable{1}, int_movable{2}),
      fcppt::math::matrix::row(int_movable{3}, int_movable{4})};

  CHECK(mat.m00().value() == 1);
  CHECK(mat.m01().value() == 2);
  CHECK(mat.m10().value() == 3);
  CHECK(mat.m11().value() == 4);
}

TEST_CASE("math::matrix::static no_init", "[math],[matrix]")
{
  using matrix22 = fcppt::math::matrix::static_<int,2,2>;

  matrix22 const no_init{fcppt::no_init{}};
  CHECK(no_init.storage().data() != nullptr);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

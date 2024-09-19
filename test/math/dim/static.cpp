//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::dim::static", "[math],[dim]")
{
  using int2_dim = fcppt::math::dim::static_<int, 2>;

  int2_dim const dim{0, 1};

  CHECK(dim.w() == 0);

  CHECK(dim.h() == 1);
}

TEST_CASE("math::dim::static no_init", "[math],[dim]")
{
  using int2_dim = fcppt::math::dim::static_<int, 2>;

  int2_dim const dim{fcppt::no_init{}};

  CHECK(dim.storage().data() != nullptr);
}

TEST_CASE("math::dim::static move", "[math],[dim]")
{
  using int_movable = fcppt::catch_::movable<int>;
  using int2_dim = fcppt::math::dim::static_<int_movable, 2>;

  int2_dim const dim{int_movable{0}, int_movable{1}};

  CHECK(dim.w().value() == 0);
  CHECK(dim.h().value() == 1);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

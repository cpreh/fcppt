//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/join.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("array::join", "[array]")
{
  CHECK(
      fcppt::array::join(
          fcppt::array::object<int, 2>{1, 2},
          fcppt::array::object<int, 3>{3, 4, 5},
          fcppt::array::object<int, 2>{6, 7}) == fcppt::array::object<int, 7>{1, 2, 3, 4, 5, 6, 7});
}

TEST_CASE("array::join move", "[array]")
{
  using int_movable = fcppt::catch_::movable<int>;

  CHECK(
      fcppt::array::join(
          fcppt::array::object<int_movable, 2>{int_movable{1}, int_movable{2}},
          fcppt::array::object<int_movable, 3>{int_movable{3}, int_movable{4}, int_movable{5}},
          fcppt::array::object<int_movable, 2>{int_movable{6}, int_movable{7}}) ==
      fcppt::array::object<int_movable, 7>{
          int_movable{1},
          int_movable{2},
          int_movable{3},
          int_movable{4},
          int_movable{5},
          int_movable{6},
          int_movable{7}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

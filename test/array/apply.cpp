//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/unit_output.hpp> // IWYU pragma: keep
#include <fcppt/array/apply.hpp>
#include <fcppt/array/make.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("array::apply", "[array]")
{
  CHECK(
      fcppt::array::apply(
          [](int const _value1, bool const _value2) { return std::make_pair(_value1, _value2); },
          fcppt::array::make(1, 2),
          fcppt::array::make(true, false)) ==
      fcppt::array::object<std::pair<int, bool>, 2>{std::make_pair(1, true), std::make_pair(2, false)});
}

TEST_CASE("array::apply move", "[array]")
{
  using int_movable = fcppt::catch_::movable<int>;

  CHECK(
      fcppt::array::apply(
          [](int_movable &&_arg1, int_movable &&_arg2) {
            return std::make_pair(std::move(_arg1), std::move(_arg2));
          },
          fcppt::array::make(int_movable{1}),
          fcppt::array::make(int_movable{2})) ==
      fcppt::array::object<std::pair<int_movable, int_movable>, 1>{
          std::make_pair(int_movable{1}, int_movable{2})});
}

TEST_CASE("array::apply empty", "[array]")
{
  CHECK(
      fcppt::array::apply(
          [](bool, int) { return fcppt::unit{}; }, fcppt::array::object<bool, 0>{}, fcppt::array::object<int, 0>{}) ==
      fcppt::array::object<fcppt::unit, 0>{});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

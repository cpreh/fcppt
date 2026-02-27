//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp> // IWYU pragma: keep
#include <fcppt/strong_typedef_output.hpp> // IWYU pragma: keep
#include <fcppt/use.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/map.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("tuple::map", "[tuple]")
{
  fcppt::tuple::object<std::integral_constant<int, 2>, std::integral_constant<int, 3>> const result{
      fcppt::tuple::map(
          fcppt::tuple::make(std::integral_constant<int, 1>{}, std::integral_constant<int, 2>{}),
          [](auto const _arg) {
            return std::integral_constant<int, std::remove_const_t<decltype(_arg)>::value + 1U>{};
          })};

  FCPPT_USE(result);
}

TEST_CASE("tuple::map move", "[tuple]")
{
  using int_movable = fcppt::catch_::movable<int>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  CHECK(fcppt::tuple::map(fcppt::tuple::make(int_movable{1}), [](int_movable &&_value) {
          return strong_int_movable{std::move(_value)};
        }) == fcppt::tuple::make(strong_int_movable{int_movable{1}}));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

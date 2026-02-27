//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_map.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

namespace
{
enum class test_enum : std::uint8_t
{
  enum1,
  enum2
};
}
FCPPT_ENUM_DEFINE_MAX_VALUE(test_enum::enum2)

TEST_CASE("enum_::array_map", "[enum]")
{
  CHECK(
      fcppt::enum_::array_map(
          fcppt::enum_::array<test_enum, int>{1, 2},
          [](int const _value) -> std::string { return fcppt::output_to_std_string(_value); }) ==
      fcppt::enum_::array<test_enum, std::string>{std::string{"1"}, std::string{"2"}});
}

TEST_CASE("enum_::array_map move", "[enum]")
{
  using int_movable = fcppt::catch_::movable<int>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  CHECK(
      fcppt::enum_::array_map(
          fcppt::enum_::array<test_enum, int_movable>{int_movable{1}, int_movable{2}},
          [](int_movable &&_arg) { return strong_int_movable{std::move(_arg)}; }) ==
      fcppt::enum_::array<test_enum, strong_int_movable>{
          strong_int_movable{int_movable{1}}, strong_int_movable{int_movable{2}}});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

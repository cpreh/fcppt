//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/array/map.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("array::map", "[array]")
{
  CHECK(fcppt::array::map(fcppt::array::object<int, 2>{1, 2}, [](int const _value) -> std::string {
          return fcppt::output_to_std_string(_value);
        }) == fcppt::array::object<std::string, 2>{std::string{"1"}, std::string{"2"}});
}

TEST_CASE("array::map move", "[array]")
{
  using int_movable = fcppt::catch_::movable<int>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  CHECK(
      fcppt::array::map(
          fcppt::array::object<int_movable, 2>{int_movable{1}, int_movable{2}},
          [](int_movable &&_arg) { return strong_int_movable{std::move(_arg)}; }) ==
      fcppt::array::object<strong_int_movable, 2>{
          strong_int_movable{int_movable{1}}, strong_int_movable{int_movable{2}}});
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::map", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_bool = fcppt::either::object<std::string, bool>;

  auto const map_function([](int const _value) { return _value > 10; });

  CHECK(
      fcppt::either::map(either_int(std::string("test")), map_function) ==
      either_bool(std::string("test")));

  CHECK(fcppt::either::map(either_int(20), map_function) == either_bool(true));
}

TEST_CASE("either::map move", "[either]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using either_int = fcppt::either::object<std::string, int_movable>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  auto const map_function(
      [](int_movable &&_value) { return strong_int_movable{std::move(_value)}; });

  CHECK(
      fcppt::either::map(either_int{int_movable{20}}, map_function) ==
      fcppt::either::object<std::string, strong_int_movable>{strong_int_movable{int_movable{20}}});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/make_movable.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/either/apply.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("either::apply", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_uint = fcppt::either::object<std::string, unsigned>;

  using either_bool = fcppt::either::object<std::string, bool>;

  auto const apply_function(
      [](int const _value1, unsigned const _value2) -> bool
      { return _value1 > 10 && _value2 < 100U; });

  CHECK(
      fcppt::either::apply(
          apply_function, either_int(std::string("test")), either_uint(std::string("test2"))) ==
      either_bool(std::string("test")));

  CHECK(
      fcppt::either::apply(apply_function, either_int(42), either_uint(std::string("test2"))) ==
      either_bool(std::string("test2")));

  CHECK(
      fcppt::either::apply(apply_function, either_int(20), either_uint(100U)) ==
      either_bool(false));
}

TEST_CASE("either::apply move", "[either]")
{
  using either_int = fcppt::either::object<std::string, fcppt::catch_::movable<int>>;

  using either_uint = fcppt::either::object<std::string, fcppt::catch_::movable<unsigned>>;

  using either_bool = fcppt::either::object<std::string, bool>;

  auto const apply_function(
      [](fcppt::catch_::movable<int> &&_value1, fcppt::catch_::movable<unsigned> &&_value2) -> bool
      { return _value1.value() > 10 && _value2.value() < 100U; });

  CHECK(
      fcppt::either::apply(
          apply_function, either_int(std::string("test")), either_uint(std::string("test2"))) ==
      either_bool(std::string("test")));

  CHECK(
      fcppt::either::apply(
          apply_function,
          either_int(fcppt::catch_::make_movable(42)),
          either_uint(std::string("test2"))) == either_bool(std::string("test2")));

  CHECK(
      fcppt::either::apply(
          apply_function,
          either_int(fcppt::catch_::make_movable(20)),
          either_uint(fcppt::catch_::make_movable(100U))) == either_bool(false));
}

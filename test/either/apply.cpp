//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

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
      [](int const _value1, unsigned const _value2) { return _value1 > 10 && _value2 < 100U; });

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

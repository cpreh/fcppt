//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::maybe", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  CHECK(
      fcppt::optional::maybe(
          optional_int(10),
          [] { return std::string{}; },
          [](int const _val) { return std::to_string(_val); }) == "10");

  CHECK(
      fcppt::optional::maybe(
          optional_int(), [] { return std::string("42"); }, [](int) { return std::string{}; }) ==
      "42");
}

TEST_CASE("optional::maybe move", "[optional]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using optional_int_unique_ptr = fcppt::optional::object<int_unique_ptr>;

  int_unique_ptr const result(fcppt::optional::maybe(
      optional_int_unique_ptr(fcppt::make_unique_ptr<int>(42)),
      [] { return fcppt::make_unique_ptr<int>(10); },
      [](int_unique_ptr &&_ptr) { return std::move(_ptr); }));

  CHECK(*result == 42);
}

FCPPT_CATCH_END

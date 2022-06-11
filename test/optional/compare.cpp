//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional equal", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  optional_int const test1(1);

  optional_int const test2(2);

  optional_int const test3;

  CHECK(test1 != test2);

  CHECK(test2 != test1);

  CHECK(test1 == test1);

  CHECK(test1 != test3);

  CHECK(test3 != test1);

  CHECK(test3 == test3);
}

TEST_CASE("optional less", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  CHECK_FALSE(optional_int() < optional_int());

  CHECK(optional_int() < optional_int(10));

  CHECK_FALSE(optional_int(10) < optional_int());

  CHECK(optional_int(5) < optional_int(10));

  CHECK_FALSE(optional_int(10) < optional_int(5));
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("optional::reference", "[optional]")
{
  using optional_int_ref = fcppt::optional::reference<int>;

  optional_int_ref const test1{};

  CHECK_FALSE(test1.has_value());

  int val{1};

  optional_int_ref test2(fcppt::make_ref(val));

  REQUIRE(test2.has_value());

  CHECK(test2.get_unsafe().get() == 1);

  test2 = test1;

  CHECK_FALSE(test2.has_value());
}

TEST_CASE("optional::reference const"
          "[optional]")
{
  using optional_int_ref_const = fcppt::optional::reference<int const>;

  optional_int_ref_const const test1{};

  CHECK_FALSE(test1.has_value());

  int const val1{1};

  optional_int_ref_const test2(fcppt::make_cref(val1));

  REQUIRE(test2.has_value());

  CHECK(test2.get_unsafe().get() == 1);

  int val2{2};

  optional_int_ref_const test3(fcppt::make_cref(val2));

  REQUIRE(test3.has_value());

  CHECK(test3.get_unsafe().get() == 2);

  test3 = test1;

  CHECK_FALSE(test3.has_value());
}

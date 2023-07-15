//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

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

  int const val2{2};

  optional_int_ref_const test3(fcppt::make_cref(val2));

  REQUIRE(test3.has_value());

  CHECK(test3.get_unsafe().get() == 2);

  test3 = test1;

  CHECK_FALSE(test3.has_value());
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

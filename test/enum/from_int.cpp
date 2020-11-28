//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/enum/from_int.hpp>
#include <fcppt/enum/from_int_exn.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum
{
  enum1,
  enum2,
  fcppt_maximum = enum2
};

}

TEST_CASE("enum::from_int", "[enum]")
{
  CHECK(fcppt::enum_::from_int<test_enum>(1U) == fcppt::optional::make(test_enum::enum2));

  CHECK(fcppt::enum_::from_int<test_enum>(2U) == fcppt::optional::object<test_enum>{});
}

TEST_CASE("enum::from_int_exn", "[enum]")
{
  CHECK(fcppt::enum_::from_int_exn<test_enum>(1U) == test_enum::enum2);

  CHECK_THROWS_AS(fcppt::enum_::from_int_exn<test_enum>(2U), fcppt::exception);
}

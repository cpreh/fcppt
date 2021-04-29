//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum
{
  test1,
  test2,
  test3,
  fcppt_maximum = test3
};

using bitfield = fcppt::container::bitfield::object<test_enum>;

static_assert(bitfield::array_size::value == 1U);
}

TEST_CASE("container::bitfield object", "[container],[bitfield]")
{
  bitfield const field1{test_enum::test1, test_enum::test3};

  CHECK(field1.get(test_enum::test1));

  CHECK_FALSE(field1.get(test_enum::test2));

  CHECK(field1.get(test_enum::test3));
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum
{
  test1,
  test2,
  test3,
  test4,
  test5,
  test6,
  test7,
  test8,
  test9,
  fcppt_maximum = test9
};

using bitfield = fcppt::container::bitfield::object<test_enum,std::uint8_t>;

static_assert(bitfield::array_size::value == 2U);
}

TEST_CASE("container::bitfield large", "[container],[bitfield]")
{
  bitfield const field{test_enum::test7,test_enum::test9};

  CHECK_FALSE(field.get(test_enum::test1));
  CHECK_FALSE(field.get(test_enum::test2));
  CHECK_FALSE(field.get(test_enum::test3));
  CHECK_FALSE(field.get(test_enum::test4));
  CHECK_FALSE(field.get(test_enum::test5));
  CHECK_FALSE(field.get(test_enum::test6));
  CHECK_FALSE(field.get(test_enum::test8));

  CHECK(field.get(test_enum::test7));
  CHECK(field.get(test_enum::test9));
}

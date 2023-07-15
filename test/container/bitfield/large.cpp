//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
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
  test10,
  test11,
  fcppt_maximum = test11
};

using bitfield = fcppt::container::bitfield::object<test_enum,std::uint8_t>;

static_assert(bitfield::array_size::value == 2U);
}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::bitfield large", "[container],[bitfield]")
{
  bitfield field{test_enum::test7,test_enum::test9};

  CHECK_FALSE(field.get(test_enum::test1));
  CHECK_FALSE(field.get(test_enum::test2));
  CHECK_FALSE(field.get(test_enum::test3));
  CHECK_FALSE(field.get(test_enum::test4));
  CHECK_FALSE(field.get(test_enum::test5));
  CHECK_FALSE(field.get(test_enum::test6));
  CHECK_FALSE(field.get(test_enum::test8));
  CHECK_FALSE(field.get(test_enum::test10));
  CHECK_FALSE(field.get(test_enum::test11));

  CHECK(field.get(test_enum::test7));
  CHECK(field.get(test_enum::test9));

  field.set(test_enum::test8, true);

  CHECK(field.get(test_enum::test8));
  CHECK(field.get(test_enum::test9));
  CHECK_FALSE(field.get(test_enum::test10));
  CHECK_FALSE(field.get(test_enum::test11));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

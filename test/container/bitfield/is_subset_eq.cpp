//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/is_subset_eq.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum : std::uint8_t
{
  test1,
  test2,
  test3
};
}
FCPPT_ENUM_DEFINE_MAX_VALUE(test_enum::test3)

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::bitfield::is_subset_eq", "[container],[bitfield]")
{
  using bitfield = fcppt::container::bitfield::object<test_enum>;

  bitfield field1(bitfield::null());

  bitfield field2(bitfield::null());

  CHECK(fcppt::container::bitfield::is_subset_eq(field1, field2));

  CHECK(fcppt::container::bitfield::is_subset_eq(field2, field1));

  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
  field2[test_enum::test1] = true;

  CHECK(fcppt::container::bitfield::is_subset_eq(field1, field2));

  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
  field1[test_enum::test2] = true;

  CHECK_FALSE(fcppt::container::bitfield::is_subset_eq(field1, field2));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

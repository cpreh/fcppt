//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/std_hash.hpp> // IWYU pragma: keep
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum : std::uint8_t
{
  test1,
  test2
};
}
FCPPT_ENUM_DEFINE_MAX_VALUE(test_enum::test2)

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::bitfield hash", "[container],[bitfield]")
{
  using bitfield = fcppt::container::bitfield::object<test_enum>;

  using bitfield_set = std::unordered_set<bitfield>;

  bitfield_set const values{
      bitfield{test_enum::test1}, bitfield{test_enum::test1, test_enum::test2}};

  CHECK(values.contains(bitfield{test_enum::test1, test_enum::test2}));

  CHECK(values.contains(bitfield{test_enum::test1}));

  CHECK_FALSE(values.contains(bitfield{test_enum::test2}));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/optional.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/enum/index_of_array.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
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
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("enum::index_of_array", "[enum]")
{
  using array = fcppt::enum_::array<test_enum, unsigned>;

  array const test{1U, 2U};

  CHECK(fcppt::enum_::index_of_array(test, 2U) == fcppt::optional::make(test_enum::test2));

  CHECK(fcppt::enum_::index_of_array(test, 3U) == fcppt::optional::object<test_enum>{});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

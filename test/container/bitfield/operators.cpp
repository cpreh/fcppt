//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/container/bitfield/output.hpp> // IWYU pragma: keep
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <string_view>
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

namespace fcppt::enum_
{
template <>
struct to_string_impl<test_enum>
{
  static std::string_view get(test_enum const _val)
  {
#define NAME_CASE(val) FCPPT_ENUM_TO_STRING_CASE(test_enum, val)
    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
    switch (_val)
    {
      NAME_CASE(test1);
      NAME_CASE(test2);
      NAME_CASE(test3);
    }
    FCPPT_PP_POP_WARNING
    throw fcppt::enum_::make_invalid(_val);
#undef NAME_CASE
  }
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::bitfield operators", "[container],[bitfield]")
{
  using bitfield = fcppt::container::bitfield::object<test_enum>;

  bitfield field1{bitfield::null()};

  field1[test_enum::test1] = true;

  bitfield field2(bitfield::null());

  CHECK((field2 | test_enum::test2)[test_enum::test2]);

  field2[test_enum::test3] = true;

  CHECK((field1 | field2) == bitfield{test_enum::test1, test_enum::test3});

  CHECK((field1 & field2) == bitfield::null());

  CHECK((field1 ^ field2) == bitfield{test_enum::test1, test_enum::test3});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

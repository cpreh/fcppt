//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/output_to_std_wstring.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/output.hpp> // NOLINT(misc-include-cleaner)
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
#include <string>
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

TEST_CASE("container::bitfield output", "[container],[bitfield]")
{
  using bitfield = fcppt::container::bitfield::object<test_enum>;

  CHECK(fcppt::output_to_std_string(bitfield{test_enum::test3}) == std::string{"{test3}"});
  CHECK(
      fcppt::output_to_std_string(bitfield{test_enum::test1, test_enum::test2}) ==
      std::string{"{test1,test2}"});
  CHECK(fcppt::output_to_std_string(bitfield{}) == std::string{"{}"});

  CHECK(fcppt::output_to_std_wstring(bitfield{test_enum::test3}) == std::wstring{L"{test3}"});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

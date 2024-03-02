//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/output_to_std_wstring.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class my_enum
{
  val1,
  val2,
  val3,
  fcppt_maximum = val3
};
}

namespace fcppt::enum_
{
template <>
struct to_string_impl<my_enum>
{
  static std::string_view get(my_enum const _val)
  {
#define NAME_CASE(val) FCPPT_ENUM_TO_STRING_CASE(my_enum, val)
    switch (_val)
    {
      NAME_CASE(val1);
      NAME_CASE(val2);
      NAME_CASE(val3);
    }
    throw fcppt::enum_::make_invalid(_val);
#undef NAME_CASE
  }
};
}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("enum::array output", "[enum]")
{
  using int_array = fcppt::enum_::array<my_enum, int>;

  CHECK(fcppt::output_to_std_string(int_array{1,2,3}) == std::string{"[val1=1,val2=2,val3=3]"});

  CHECK(fcppt::output_to_std_wstring(int_array{1,2,3}) == std::wstring{L"[val1=1,val2=2,val3=3]"});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

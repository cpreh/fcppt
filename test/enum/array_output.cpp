//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_std_string.hpp>
#include <fcppt/output_to_std_wstring.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_output.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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
	FCPPT_ASSERT_UNREACHABLE;
#undef NAME_CASE
  }
};
}

FCPPT_CATCH_BEGIN

TEST_CASE("enum::array output", "[enum]")
{
  using int_array = fcppt::enum_::array<my_enum, int>;

  CHECK(fcppt::output_to_std_string(int_array{1,2,3}) == std::string{"[val1=1,val2=2,val3=3]"});

  CHECK(fcppt::output_to_std_wstring(int_array{1,2,3}) == std::wstring{L"[val1=1,val2=2,val3=3]"});
}

FCPPT_CATCH_END

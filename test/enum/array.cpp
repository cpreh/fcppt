//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/assert/unreachable.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_output.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
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

TEST_CASE("enum::array", "[enum]")
{
  using int_array = fcppt::enum_::array<my_enum, int>;

  int_array const test1{1, 2, 3};
  CHECK(test1.begin() + 3U == test1.end());
  CHECK(test1.data() == &*test1.begin());

  CHECK(test1[my_enum::val1] == 1);

  int_array const test2{1, 2, 3};

  CHECK(test1 == test2);

  int_array const test3{1, 2, 4};

  CHECK(test1 != test3);
}

FCPPT_CATCH_END

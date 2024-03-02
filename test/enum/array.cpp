//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/enum/array.hpp>
#include <fcppt/enum/array_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/enum/to_string_impl_fwd.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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
    throw fcppt::enum_::make_invalid(_val);
#undef NAME_CASE
  }
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

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

FCPPT_PP_POP_WARNING

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

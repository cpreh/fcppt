//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
enum class test_enum
{
  test1,
  test2,
  test3,
  fcppt_maximum = test3
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

// NOLINTNEXTLINE(fuchsia-statically-constructed-objects)
fcppt::enum_::names_array<test_enum> const names{{{// NOLINT(cert-err58-cpp)
                                                   FCPPT_TEXT("test1"),
                                                   FCPPT_TEXT("test2"),
                                                   FCPPT_TEXT("test3")}}};

FCPPT_PP_POP_WARNING

}

namespace fcppt::enum_
{
template <>
struct names_impl<test_enum>
{
  static fcppt::enum_::names_array<test_enum> const &get() { return ::names; }
};

}

TEST_CASE("enum::to_string", "[enum]")
{
  CHECK(fcppt::enum_::to_string(test_enum::test1) == FCPPT_TEXT("test1"));

  CHECK(fcppt::enum_::to_string(test_enum::test2) == FCPPT_TEXT("test2"));
}

TEST_CASE("enum::from_string", "[enum]")
{
  CHECK(
      fcppt::enum_::from_string<test_enum>(FCPPT_TEXT("xy")) ==
      fcppt::optional::object<test_enum>{});

  CHECK(
      fcppt::enum_::from_string<test_enum>(FCPPT_TEXT("test2")) ==
      fcppt::optional::make(test_enum::test2));
}

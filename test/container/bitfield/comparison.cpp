//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/output.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
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
fcppt::enum_::names_array<test_enum> const names{// NOLINT(cert-err58-cpp)
                                                 fcppt::string{FCPPT_TEXT("test1")},
                                                 fcppt::string{FCPPT_TEXT("test2")},
                                                 fcppt::string{FCPPT_TEXT("test3")}};

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

TEST_CASE("container::bitfield comparison", "[container],[bitfield]")
{
  using bitfield = fcppt::container::bitfield::enum_object<test_enum>;

  bitfield field1(bitfield::null());

  bitfield field2(bitfield::null());

  CHECK(field1 == field2);

  field2[test_enum::test2] = true;

  CHECK(field1 != field2);

  CHECK(field1 < field2);

  std::swap(field1, field2);

  CHECK(field2 < field1);
}

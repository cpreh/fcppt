//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/bitfield/init.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::bitfield::init", "[container],[bitfield]")
{
  enum class my_enum : std::uint8_t
  {
    test1,
    test2,
    test3,
    fcppt_maximum = test3
  };

  using bitfield = fcppt::container::bitfield::object<my_enum>;

  auto const test(fcppt::container::bitfield::init<bitfield>([](my_enum const _value) {
    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
    switch (_value)
    {
    case my_enum::test1:
    case my_enum::test3:
      return true;
    case my_enum::test2:
      return false;
    }
    FCPPT_PP_POP_WARNING

    throw fcppt::enum_::make_invalid(_value);
  }));

  CHECK(test[my_enum::test1]);

  CHECK_FALSE(test[my_enum::test2]);

  CHECK(test[my_enum::test3]);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

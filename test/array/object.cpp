//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/get.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

template class fcppt::array::object<int,2U>;

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

TEST_CASE("array::array", "[array]")
{
  fcppt::array::object<int,2U> const test{4,8};
  static_assert(test.size() == 2U);

  CHECK(fcppt::array::get<0>(test) == 4);
  CHECK(test.get_unsafe(0) == 4);
  CHECK(fcppt::array::get<1>(test) == 8);
  CHECK(test.get_unsafe(1) == 8);
  CHECK(test.begin() + 2U == test.end());
  CHECK(test.data() == &*test.begin());

  constexpr fcppt::array::object<int,1U> const c1{1};
  static_assert(fcppt::array::get<0>(c1) == 1);

  fcppt::array::object<int,1U> test2{c1};
  fcppt::array::get<0>(test2) = 10;
  CHECK(fcppt::array::get<0>(test2) == 10);
  CHECK(test2.begin() + 1U == test2.end());
  CHECK(test2.data() == &*test2.begin());
  CHECK(test2.size() == 1U);
}

FCPPT_PP_POP_WARNING

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

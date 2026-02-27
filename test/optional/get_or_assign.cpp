//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/get_or_assign.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/ignore_dangling_reference.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_DANGLING_REFERENCE

TEST_CASE("optional::get_or_assign", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  optional_int test{};

  int const &result1{fcppt::optional::get_or_assign(test, fcppt::const_(1))};

  CHECK(result1 == 1);

  int const &result2{fcppt::optional::get_or_assign(test, fcppt::const_(2))};

  CHECK(result2 == 1);
}

FCPPT_PP_POP_WARNING

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

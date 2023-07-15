//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/assign.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/ignore_dangling_reference.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_DANGLING_REFERENCE

TEST_CASE("optional::assign", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  optional_int test;

  int const &result{fcppt::optional::assign(test, 1)};

  CHECK(result == 1);
}

TEST_CASE("optional::assign move", "[optional]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using optional_int_unique_ptr = fcppt::optional::object<int_unique_ptr>;

  optional_int_unique_ptr test;

  int_unique_ptr const &result{fcppt::optional::assign(test, fcppt::make_unique_ptr<int>(1))};

  CHECK(*result == 1);
}

FCPPT_PP_POP_WARNING

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp> // IWYU pragma: keep
#include <fcppt/reference_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::from_pointer", "[optional]")
{
  using optional_ref = fcppt::optional::reference<int>;

  int value{0};

  CHECK(fcppt::optional::from_pointer(&value) == optional_ref{fcppt::make_ref(value)});

  int *const ptr(nullptr);

  CHECK(fcppt::optional::from_pointer(ptr) == optional_ref{});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

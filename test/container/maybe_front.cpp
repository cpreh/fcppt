//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp> // IWYU pragma: keep
#include <fcppt/reference_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::maybe_front", "[container]")
{
  using int_vector = std::vector<int>;

  using optional_int_ref = fcppt::optional::reference<int const>;

  int_vector const empty{};

  CHECK(fcppt::container::maybe_front(empty) == optional_int_ref{});

  int_vector const vec12{1, 2};

  CHECK(fcppt::container::maybe_front(vec12) == optional_int_ref(fcppt::make_cref(vec12.front())));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

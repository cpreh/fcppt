//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/error_from_optional.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/no_error_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/no_error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::error_from_optional", "[either]")
{
  using optional_int = fcppt::optional::object<int>;

  using either_int = fcppt::either::error<int>;

  CHECK(fcppt::either::error_from_optional(optional_int{42}) == either_int{42});

  CHECK(
      fcppt::either::error_from_optional(optional_int()) == either_int{fcppt::either::no_error{}});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <climits>
#include <limits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("cast::truncation_check", "[cast]")
{
#if SHRT_MAX < LONG_MAX
  CHECK(
      fcppt::cast::truncation_check<short>(std::numeric_limits<long>::max()) ==
      fcppt::optional::object<short>{});

  CHECK(
      fcppt::cast::truncation_check<short>(std::numeric_limits<long>::min()) ==
      fcppt::optional::object<short>{});
#endif
  CHECK(
      fcppt::cast::truncation_check<long>(std::numeric_limits<unsigned long>::max()) ==
      fcppt::optional::object<long>{});

  CHECK(
      fcppt::cast::truncation_check<unsigned long>(-1) == fcppt::optional::object<unsigned long>{});

#if USHRT_MAX < ULONG_MAX
  CHECK(
      fcppt::cast::truncation_check<unsigned short>(std::numeric_limits<unsigned long>::max()) ==
      fcppt::optional::object<unsigned short>{});
#endif
  CHECK(fcppt::cast::truncation_check<unsigned>(10U) == fcppt::optional::make(10U));

  CHECK(fcppt::cast::truncation_check<unsigned long>(42U) == fcppt::optional::make(42UL));

  CHECK(fcppt::cast::truncation_check<long>(-1) == fcppt::optional::make(-1L));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

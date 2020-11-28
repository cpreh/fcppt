//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <climits>
#include <limits>
#include <fcppt/config/external_end.hpp>

TEST_CASE("cast::truncation_check", "[cast]")
{
#if SHRT_MAX < LONG_MAX
  CHECK_THROWS_AS(
      fcppt::cast::truncation_check<short>(std::numeric_limits<long>::max()),
      fcppt::cast::bad_truncation_check);

  CHECK_THROWS_AS(
      fcppt::cast::truncation_check<short>(std::numeric_limits<long>::min()),
      fcppt::cast::bad_truncation_check);
#endif
  CHECK_THROWS_AS(
      fcppt::cast::truncation_check<long>(std::numeric_limits<unsigned long>::max()),
      fcppt::cast::bad_truncation_check);

  CHECK_THROWS_AS(
      fcppt::cast::truncation_check<unsigned long>(-1), fcppt::cast::bad_truncation_check);

#if USHRT_MAX < ULONG_MAX
  CHECK_THROWS_AS(
      fcppt::cast::truncation_check<unsigned short>(std::numeric_limits<unsigned long>::max()),
      fcppt::cast::bad_truncation_check);
#endif
  CHECK(fcppt::cast::truncation_check<unsigned>(10U) == 10U);

  CHECK(fcppt::cast::truncation_check<unsigned long>(42U) == 42UL);

  CHECK(fcppt::cast::truncation_check<long>(-1) == -1L);
}

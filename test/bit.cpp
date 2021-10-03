//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/bit/mask.hpp>
#include <fcppt/bit/mask_c.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/shifted_mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{

static_assert(fcppt::bit::shifted_mask_c<unsigned, 10>().get() == 1U << 10U);

}

FCPPT_CATCH_BEGIN

TEST_CASE("bit", "[bit]")
{
  CHECK(fcppt::bit::shifted_mask<unsigned>(10).get() == 1U << 10U);

  CHECK(fcppt::bit::shifted_mask<std::uint8_t>(3).get() == std::uint8_t{1U} << 3U);

  auto const mask_c(fcppt::bit::mask_c<unsigned, 0xFFU>());

  CHECK(mask_c.get() == 0xFFU);

  CHECK_FALSE(fcppt::bit::test(0xF0U, fcppt::bit::mask<unsigned>(0x0FU)));

  CHECK(fcppt::bit::test(0xF0U, fcppt::bit::mask<unsigned>(0x1FU)));
}

FCPPT_CATCH_END

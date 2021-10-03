//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/clamp.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::clamp", "[math]")
{
  CHECK(fcppt::math::clamp(-5, 5, 10) == fcppt::optional::make(5));
  CHECK(fcppt::math::clamp(15, 5, 10) == fcppt::optional::make(10));
  CHECK(fcppt::math::clamp(15, 10, 5) == fcppt::optional::object<int>{});
}

FCPPT_CATCH_END

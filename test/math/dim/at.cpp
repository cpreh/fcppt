//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::dim::at", "[math],[dim]")
{
  using dim2 = fcppt::math::dim::static_<int, 2>;

  dim2 const dim_c(1, 2);

  CHECK(fcppt::math::dim::at<0>(dim_c) == 1);

  CHECK(fcppt::math::dim::at<1>(dim_c) == 2);

  dim2 dim_m(1, 2);

  fcppt::math::dim::at<1>(dim_m) = 42;

  CHECK(fcppt::math::dim::at<1>(dim_m) == 42);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

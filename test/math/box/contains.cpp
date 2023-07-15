//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/box/contains.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::box::contains", "[math],[box]")
{
  using box2 = fcppt::math::box::rect<int>;

  box2 const outer{box2::vector{0, 0}, box2::dim{5, 5}};

  CHECK(fcppt::math::box::contains(outer, box2{box2::vector{1, 1}, box2::dim{2, 2}}));

  CHECK_FALSE(fcppt::math::box::contains(outer, box2{box2::vector{-1, 1}, box2::dim{2, 2}}));

  CHECK_FALSE(fcppt::math::box::contains(outer, box2{box2::vector{1, 1}, box2::dim{2, 5}}));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

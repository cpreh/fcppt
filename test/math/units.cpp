//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/is_zero_boost_units.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math units", "[math]")
{
  using unit_type = int;

  using length = boost::units::quantity<boost::units::si::length, unit_type>;

  using time = boost::units::quantity<boost::units::si::time, unit_type>;

  using velocity = boost::units::quantity<boost::units::si::velocity, unit_type>;

  using length2 = fcppt::math::vector::static_<length, 2>;

  using time2 = fcppt::math::vector::static_<time, 2>;

  using velocity2 = fcppt::math::vector::static_<velocity, 2>;

  length2 const l1{length{-100 * boost::units::si::meter}, length{200 * boost::units::si::meter}};

  time2 const t1{time{4 * boost::units::si::second}, time{2 * boost::units::si::second}};

  CHECK(
      l1 / t1 == fcppt::optional::make(velocity2{
                     -25 * boost::units::si::meter / boost::units::si::second,
                     100 * boost::units::si::meter / boost::units::si::second}));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/box/componentwise_equal.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::box::componentwise_equal", "[math],[box]")
{
  using box_type = fcppt::math::box::object<float, 2>;

  float const epsilon{0.00001F};

  CHECK(fcppt::math::box::componentwise_equal(
      box_type{box_type::vector{1.F, 2.F}, box_type::dim{3.F, 4.F}},
      box_type{box_type::vector{1.F, 2.F}, box_type::dim{3.F, 4.F}},
      epsilon));

  CHECK_FALSE(fcppt::math::box::componentwise_equal(
      box_type{box_type::vector{1.F, 2.F}, box_type::dim{3.F, 4.F}},
      box_type{box_type::vector{1.1F, 2.F}, box_type::dim{3.F, 4.F}},
      epsilon));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

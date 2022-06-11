//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector comparison", "[math],[vector]")
{
  using uivector2 = fcppt::math::vector::static_<unsigned, 2>;

  uivector2 const vec1(1U, 2U);
  uivector2 const vec2(1U, 2U);
  uivector2 const vec3(2U, 2U);

  CHECK(vec1 == vec2);

  CHECK(vec2 != vec3);

  CHECK(vec1 < vec3);
}

FCPPT_CATCH_END

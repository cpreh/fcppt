//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("math::vector::hash", "[math],[vector]")
{
  using int3_vector = fcppt::math::vector::static_<int, 3>;

  using vector_set = std::unordered_set<int3_vector>;

  vector_set const set{int3_vector(1, 2, 3)};

  CHECK(set.contains(int3_vector(1, 2, 3)));

  CHECK_FALSE(set.contains(int3_vector(4, 2, 3)));
}

FCPPT_CATCH_END

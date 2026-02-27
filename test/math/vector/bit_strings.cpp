//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/object.hpp>
#include <fcppt/array/output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/comparison.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/output.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector::bit_strings", "[math],[vector]")
{
  using vector2 = fcppt::math::vector::static_<int, 2>;

  using vector3 = fcppt::math::vector::static_<int, 3>;

  CHECK(
      fcppt::math::vector::bit_strings<int, 2>() ==
      fcppt::array::object<vector2, 4>{vector2(0, 0), vector2(1, 0), vector2(0, 1), vector2(1, 1)});

  CHECK(
      fcppt::math::vector::bit_strings<int, 3>() == fcppt::array::object<vector3, 8>{
                                                        vector3(0, 0, 0),
                                                        vector3(1, 0, 0),
                                                        vector3(0, 1, 0),
                                                        vector3(1, 1, 0),
                                                        vector3(0, 0, 1),
                                                        vector3(1, 0, 1),
                                                        vector3(0, 1, 1),
                                                        vector3(1, 1, 1)});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

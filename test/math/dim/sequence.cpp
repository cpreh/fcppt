//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/dim/comparison.hpp> // IWYU pragma: keep
#include <fcppt/math/dim/output.hpp> // IWYU pragma: keep
#include <fcppt/math/dim/sequence.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::dimx::sequence", "[math],[dim]")
{
  using ui2_dim = fcppt::math::dim::static_<unsigned, 2>;

  using ui2_dim_opt = fcppt::math::dim::static_<fcppt::optional::object<unsigned>, 2>;

  CHECK(
      fcppt::math::dim::sequence(
          ui2_dim_opt{fcppt::optional::make(10U), fcppt::optional::make(20U)}) ==
      fcppt::optional::make(ui2_dim{10U, 20U}));

  CHECK(
      fcppt::math::dim::sequence(
          ui2_dim_opt{fcppt::optional::object<unsigned>{}, fcppt::optional::make(20U)}) ==
      fcppt::optional::object<ui2_dim>{});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

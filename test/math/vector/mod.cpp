//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector::mod", "[math],[vector]")
{
  using uivector2 = fcppt::math::vector::static_<unsigned, 2>;

  using optional_uivector2 = fcppt::optional::object<uivector2>;

  CHECK(
      fcppt::math::vector::mod(uivector2{4U, 3U}, 2U) == fcppt::optional::make(uivector2{0U, 1U}));

  CHECK(fcppt::math::vector::mod(uivector2{4U, 3U}, 0U) == optional_uivector2{});

  CHECK(
      fcppt::math::vector::mod(uivector2{5U, 3U}, uivector2{3U, 2U}) ==
      fcppt::optional::make(uivector2{2U, 1U}));

  CHECK(fcppt::math::vector::mod(uivector2{4U, 3U}, uivector2{0U, 1U}) == optional_uivector2{});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

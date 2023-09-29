//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/input.hpp>
#include <fcppt/math/vector/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("math::vector input", "[math],[vector]")
{
  using ui2_vector = fcppt::math::vector::static_<unsigned, 2>;

  SECTION("input success")
  {
    fcppt::io::istringstream stream{FCPPT_TEXT("(42, 3)")};

    ui2_vector result(fcppt::no_init{});

    REQUIRE(stream >> result);

    CHECK(result == ui2_vector{42U, 3U});
  }

  SECTION("input failure")
  {
    fcppt::io::istringstream stream{FCPPT_TEXT("(42, 3")};

    ui2_vector result(fcppt::no_init{});

    CHECK_FALSE(stream >> result);
  }
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

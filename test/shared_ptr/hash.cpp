//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/shared_ptr_output.hpp> // IWYU pragma: keep
#include <fcppt/shared_ptr_std_hash.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("shared_ptr hash", "[smartptr]")
{
  using int_shared_ptr = fcppt::shared_ptr<int>;

  using int_shared_ptr_set = std::unordered_set<int_shared_ptr>;

  int_shared_ptr const x{fcppt::make_shared_ptr<int>(1)};

  int_shared_ptr_set const set{x};

  SECTION("found")
  {
    auto const it{set.find(x)};

    REQUIRE(it != set.end());

    CHECK(*it == x);
  }

  SECTION("not found")
  {
    int_shared_ptr const y{fcppt::make_shared_ptr<int>(1)};

    CHECK_FALSE(set.contains(y));
  }
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

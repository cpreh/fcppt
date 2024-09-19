//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_ref = fcppt::reference<int>;

using const_int_ref = fcppt::reference<int const>;

struct test
{
  [[nodiscard]] int value() const // NOLINT(readability-convert-member-functions-to-static)
  {
    return 42;
  }
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("reference", "[ref]")
{
  int x{1};

  int_ref ref(x);

  CHECK(&ref.get() == &x);

  const_int_ref const cref(x);

  CHECK(&cref.get() == &x);

  CHECK(&fcppt::make_ref(x).get() == &x);

  CHECK(&fcppt::make_cref(x).get() == &x);

  int_ref const other_ref{ref};

  CHECK(&other_ref.get() == &ref.get());

  ref = other_ref;

  CHECK(&other_ref.get() == &ref.get());
}

TEST_CASE("reference hash", "[ref]")
{
  using int_ref_set = std::unordered_set<int_ref>;

  SECTION("set")
  {
    int x(1);

    int_ref_set const set{int_ref(x)};

    auto const it(set.find(int_ref(x)));

    REQUIRE(it != set.end());

    CHECK(&it->get() == &x);
  }

  SECTION("const set")
  {
    using const_int_ref_set = std::unordered_set<const_int_ref>;

    int const y(1);

    const_int_ref_set const const_set{const_int_ref(y)};

    auto const it(const_set.find(const_int_ref(y)));

    REQUIRE(it != const_set.end());

    CHECK(&it->get() == &y);
  }
}

TEST_CASE("reference call", "[ref]")
{
  test t{};

  fcppt::reference<test> const ref{t};

  CHECK(ref->value() == 42);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

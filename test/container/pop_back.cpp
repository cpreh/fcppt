//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::pop_back", "[container]")
{
  using int_vector = std::vector<int>;

  int_vector empty{};

  CHECK(fcppt::container::pop_back(empty) == fcppt::optional::object<int>{});

  int_vector vec12{1, 2};

  CHECK(fcppt::container::pop_back(vec12) == fcppt::optional::make(2));

  int_vector const expected{1};

  CHECK(vec12 == expected);
}

TEST_CASE("container::pop_back move", "[container]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using int_movable_vector = std::vector<int_movable>;

  auto vector(fcppt::container::make<int_movable_vector>(int_movable{1}));

  CHECK(fcppt::container::pop_back(vector) == fcppt::optional::make(int_movable{1}));

  CHECK(vector.empty());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

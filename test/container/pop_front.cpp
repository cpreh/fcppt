//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/pop_front.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::pop_front", "[container]")
{
  using int_queue = std::deque<int>;

  int_queue empty{};

  CHECK(fcppt::container::pop_front(empty) == fcppt::optional::object<int>{});

  int_queue vec12{1, 2};

  CHECK(fcppt::container::pop_front(vec12) == fcppt::optional::make(1));

  int_queue const expected{2};

  CHECK(vec12 == expected);
}

TEST_CASE("container::pop_front move"
          "[container]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using int_movable_queue = std::deque<int_movable>;

  auto queue(fcppt::container::make<int_movable_queue>(int_movable{1}));

  CHECK(fcppt::container::pop_front(queue) == fcppt::optional::make(int_movable{1}));

  CHECK(queue.empty());
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/pop_front.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <deque>
#include <fcppt/config/external_end.hpp>

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

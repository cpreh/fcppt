//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/movable.hpp>
#include <fcppt/container/tuple/push_back.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::tuple::push_back", "[container],[tuple]")
{
  CHECK(
      fcppt::container::tuple::push_back(std::tuple<int, bool>{1, false}, std::string{"test"}) ==
      std::tuple<int, bool, std::string>{1, false, std::string{"test"}});
}

TEST_CASE("container::tuple::push_back move", "[container],[tuple]")
{
  using int_movable = fcppt::catch_::movable<int>;

  CHECK(
      fcppt::container::tuple::push_back(std::make_tuple(int_movable{1}), int_movable{2}) ==
      std::make_tuple(int_movable{1}, int_movable{2}));
}

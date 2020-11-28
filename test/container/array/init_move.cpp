//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/movable.hpp>
#include <fcppt/container/array/init_move.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>

TEST_CASE("array::init_move", "[container],[array]")
{
  using movable = fcppt::catch_::movable<int>;

  using movable_2_array = std::array<movable, 2>;

  CHECK(fcppt::container::array::init_move<movable_2_array>([] {
          return movable{42};
        }) == movable_2_array{{movable{42}, movable{42}}});
}

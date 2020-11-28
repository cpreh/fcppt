//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/map_concat.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_vector = std::vector<int>;

using int_movable = fcppt::catch_::movable<int>;

using int_movable_vector = std::vector<int_movable>;

}

TEST_CASE("algorithm map_concat"
          "[algorithm_map_concat]")
{
  CHECK(
      fcppt::algorithm::map_concat<int_vector>(
          fcppt::container::make<int_movable_vector>(int_movable{1}, int_movable{2}),
          [](int_movable const &_value) {
            return int_vector{_value.value(), _value.value() + 5};
          }) == int_vector{1, 6, 2, 7});
}

TEST_CASE("algorithm_map_concat move", "[algorithm_map_concat]")
{
  int_vector const ints{1, 2};

  CHECK(
      fcppt::algorithm::map_concat<int_movable_vector>(
          ints,
          [](int const _value) {
            return fcppt::container::make<int_movable_vector>(
                int_movable{_value}, int_movable{_value + 5});
          }) ==
      fcppt::container::make<int_movable_vector>(
          int_movable{1}, int_movable{6}, int_movable{2}, int_movable{7}));
}

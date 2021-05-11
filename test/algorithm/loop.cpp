//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/metal/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

TEST_CASE("algorithm_loop mpl"
          "[algorithm_loop]")
{
  int value{0};

  fcppt::algorithm::loop(
      fcppt::metal::interval<int, 0, 5>{},
      [&value]<int Index>(fcppt::tag<std::integral_constant<int, Index>>)
      {
        static_assert(Index < 5);

        value += Index;
      });

  CHECK(value == 10);
}

TEST_CASE("algorithm_loop_range", "[algorithm_loop]")
{
  int value{0};

  fcppt::algorithm::loop(
      fcppt::make_int_range_count(5), [&value](int const _value) { value += _value; });

  CHECK(value == 10);
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm_loop mpl"
          "[algorithm_loop]")
{
  int value{0};

  fcppt::algorithm::loop(
      fcppt::mpl::list::interval<std::integral_constant<int, 0>, std::integral_constant<int, 5>>{},
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

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

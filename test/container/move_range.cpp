//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container move_range", "[container]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using int_movable_vector = std::vector<int_movable>;

  FCPPT_DECLARE_STRONG_TYPEDEF(int_movable, strong_int_movable);

  using strong_int_movable_vector = std::vector<strong_int_movable>;

  CHECK(
      fcppt::algorithm::map<strong_int_movable_vector>(
          fcppt::container::make_move_range(
              fcppt::container::make<int_movable_vector>(int_movable{0}, int_movable{1})),
          [](int_movable &&_value) { return strong_int_movable{std::move(_value)}; }) ==
      fcppt::container::make<strong_int_movable_vector>(
          strong_int_movable{int_movable{0}}, strong_int_movable{int_movable{1}}));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/join.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <map>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container_join std::vector"
          "[container_join]")
{
  using int_vector = std::vector<int>;

  int_vector const vec3{5, 6};

  CHECK(
      fcppt::container::join(int_vector{1, 2}, int_vector{3, 4}, vec3) ==
      int_vector{1, 2, 3, 4, 5, 6});
}

TEST_CASE("container_join move"
          "[container_join]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using int_movable_vector = std::vector<int_movable>;

  CHECK(
      fcppt::container::join(
          fcppt::container::make<int_movable_vector>(int_movable{1}, int_movable{2}),
          fcppt::container::make<int_movable_vector>(int_movable{3}, int_movable{4}),
          fcppt::container::make<int_movable_vector>(int_movable{5}, int_movable{6})) ==
      fcppt::container::make<int_movable_vector>(
          int_movable{1},
          int_movable{2},
          int_movable{3},
          int_movable{4},
          int_movable{5},
          int_movable{6}));
}

TEST_CASE("container_join std::map"
          "[container_join]")
{
  using int_map = std::map<int, char>;

  CHECK(
      fcppt::container::join(
          int_map{std::make_pair(1, 'a'), std::make_pair(2, 'b')},
          int_map{std::make_pair(2, 'c'), std::make_pair(3, 'd')}) ==
      int_map{std::make_pair(1, 'a'), std::make_pair(2, 'b'), std::make_pair(3, 'd')});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

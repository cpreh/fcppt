//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/loop_break_tuple.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/map_tuple.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/optional.hpp> // IWYU pragma: keep
#include <fcppt/catch/tuple.hpp> // IWYU pragma: keep
#include <fcppt/container/make.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/sequence.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::sequence", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  using optional_int_vector = std::vector<optional_int>;

  using int_vector = std::vector<int>;

  using result_type = fcppt::optional::object<int_vector>;

  CHECK(
      fcppt::optional::sequence<int_vector>(optional_int_vector{
          optional_int{10}, optional_int{20}}) == fcppt::optional::make(int_vector{10, 20}));

  CHECK(
      fcppt::optional::sequence<int_vector>(
          optional_int_vector{optional_int{10}, optional_int{}}) == result_type{});
}

TEST_CASE("optional::sequence move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  using optional_int_movable_vector = std::vector<optional_int_movable>;

  using int_movable_vector = std::vector<int_movable>;

  using result_type = fcppt::optional::object<int_movable_vector>;

  CHECK(
      fcppt::optional::sequence<int_movable_vector>(
          fcppt::container::make<optional_int_movable_vector>(optional_int_movable{int_movable{
              42}})) == result_type{fcppt::container::make<int_movable_vector>(int_movable{42})});
}

TEST_CASE("optional::sequence tuple", "[optional]")
{
  CHECK(
      fcppt::optional::sequence<fcppt::tuple::object<int, bool>>(
          fcppt::tuple::make(fcppt::optional::make(0), fcppt::optional::make(false))) ==
      fcppt::optional::make(fcppt::tuple::make(0, false)));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

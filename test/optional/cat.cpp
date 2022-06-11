//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/cat.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::cat", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  using optional_int_vector = std::vector<optional_int>;

  using int_vector = std::vector<int>;

  CHECK(
      fcppt::optional::cat<int_vector>(optional_int_vector{optional_int{42}, optional_int{}}) ==
      int_vector{42});
}

TEST_CASE("Optional::cat move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  using int_movable_vector = std::vector<int_movable>;

  CHECK(
      fcppt::optional::cat<int_movable_vector>(
          fcppt::container::make<std::vector<optional_int_movable>>(
              optional_int_movable{int_movable{42}}, optional_int_movable{})) ==
      fcppt::container::make<int_movable_vector>(int_movable{42}));
}

FCPPT_CATCH_END

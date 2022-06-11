//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::to_container", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  using int_vector = std::vector<int>;

  CHECK(fcppt::optional::to_container<int_vector>(optional_int{42}) == int_vector{42});

  CHECK(fcppt::optional::to_container<int_vector>(optional_int{}).empty());
}

TEST_CASE("optional::to_container move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  using int_movable_vector = std::vector<int_movable>;

  CHECK(
      fcppt::optional::to_container<int_movable_vector>(optional_int_movable{int_movable{42}}) ==
      fcppt::container::make<int_movable_vector>(int_movable{42}));

  CHECK(fcppt::optional::to_container<int_movable_vector>(optional_int_movable{}).empty());
}

FCPPT_CATCH_END

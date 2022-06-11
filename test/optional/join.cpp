//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/join.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::join", "[optional]")
{
  using optional_string = fcppt::optional::object<std::string>;

  using optional_optional_string = fcppt::optional::object<optional_string>;

  CHECK(
      fcppt::optional::join(optional_optional_string(optional_string("test2"))) ==
      optional_string("test2"));

  CHECK(fcppt::optional::join(optional_optional_string()) == optional_string());
}

TEST_CASE("optional::join move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  CHECK(
      fcppt::optional::join(fcppt::optional::make(optional_int_movable{int_movable{42}})) ==
      optional_int_movable{int_movable{42}});
}

FCPPT_CATCH_END

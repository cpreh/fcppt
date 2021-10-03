//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/overload.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("tuple::init", "[tuple]")
{
  using movable = fcppt::catch_::movable<std::size_t>;

  using tuple = fcppt::tuple::object<movable, std::size_t>;

  CHECK(
      fcppt::tuple::init<tuple>(fcppt::overload(
          [](std::integral_constant<std::size_t, 0>) { return movable{0}; },
          [](std::integral_constant<std::size_t, 1>) { return std::size_t{1U}; })) ==
      tuple{movable{0U}, std::size_t{1U}});
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/tuple/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>

TEST_CASE("tuple::apply", "[container],[tuple]")
{
  CHECK(
      fcppt::container::tuple::apply(
          [](auto &&..._args) { return std::make_tuple(std::forward<decltype(_args)>(_args)...); },
          std::make_tuple(1, true, std::string{"test"}),
          std::make_tuple(false, std::string{"x"}, false)) ==
      std::make_tuple(
          std::make_tuple(1, false),
          std::make_tuple(true, std::string{"x"}),
          std::make_tuple(std::string{"test"}, false)));
}

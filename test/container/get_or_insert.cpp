//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/get_or_insert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <map>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::get_or_insert", "[container]")
{
  using int_string_map = std::map<int, std::string>;

  int_string_map map{};

  auto const inserter([](int const _value) { return std::to_string(_value); });

  std::string &inserted(fcppt::container::get_or_insert(map, 42, inserter));

  int_string_map::iterator const it{map.find(42)};

  REQUIRE(it != map.end());

  CHECK(&inserted == &it->second);

  CHECK(it->second == std::string{"42"});

  CHECK(&fcppt::container::get_or_insert(map, 42, inserter) == &it->second);
}

FCPPT_CATCH_END

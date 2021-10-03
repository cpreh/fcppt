//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/index_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::index_map", "[container]")
{
  using int_index_map = fcppt::container::index_map<int>;

  int_index_map map{};

  map[2] = 42;

  REQUIRE(map.impl().size() == 3U);

  CHECK(map[0] == 0);

  CHECK(map[1] == 0);

  CHECK(map[2] == 42);
}

FCPPT_CATCH_END

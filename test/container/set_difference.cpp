//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/set_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::set_difference", "[container]")
{
  using int_set = std::set<int>;

  CHECK(fcppt::container::set_difference(int_set{1, 2, 3}, int_set{2, 3, 4}) == int_set{1});
}

FCPPT_CATCH_END

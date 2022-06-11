//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("algorithm::reverse", "[algorithm]")
{
  using int_vector = std::vector<int>;

  int_vector const expected{3, 2, 1};

  {
    int_vector const vec{1, 2, 3};

    CHECK(fcppt::algorithm::reverse(vec) == expected);
  }

  {
    CHECK(fcppt::algorithm::reverse(int_vector{1, 2, 3}) == expected);
  }
}

FCPPT_CATCH_END

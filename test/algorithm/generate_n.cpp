//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/generate_n.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

TEST_CASE("algorithm generate_n", "[algorithm_generate_n]")
{
  using int_vector = std::vector<int>;

  CHECK(fcppt::algorithm::generate_n<int_vector>(3, [] {
          static int index{0};

          return index++;
        }) == int_vector{0, 1, 2});
}

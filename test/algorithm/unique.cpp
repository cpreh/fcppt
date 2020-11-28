//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

TEST_CASE("algorithm::unique", "[algorithm]")
{
  using int_vector = std::vector<int>;

  int_vector vec{1, 1, 2, 2, 3};

  fcppt::algorithm::unique(vec);

  CHECK(vec == int_vector{1, 2, 3});
}

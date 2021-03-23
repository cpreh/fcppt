//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/data.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::data", "[container]")
{
  using int_vector = std::vector<int>;

  int_vector container{};

  CHECK(fcppt::container::data(container) == nullptr);

  CHECK(fcppt::container::data_end(container) == nullptr);

  container.push_back(1);

  container.push_back(2);

  CHECK(
      std::distance(fcppt::container::data(container), fcppt::container::data_end(container)) == 2);
}

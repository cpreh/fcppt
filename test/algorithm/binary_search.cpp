//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/binary_search.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("algorithm binary search"
          "[algorithm]")
{
  using int_vector = std::vector<int>;

  int_vector const vec{2, 5, 7};

  CHECK(
      fcppt::algorithm::binary_search(vec, 3) ==
      fcppt::optional::object<int_vector::const_iterator>{});

  CHECK(
      fcppt::algorithm::binary_search(vec, 5) == fcppt::optional::make(std::next(vec.begin(), 1)));
}

FCPPT_CATCH_END

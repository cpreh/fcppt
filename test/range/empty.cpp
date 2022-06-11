//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/iterator/make_range.hpp>
#include <fcppt/range/empty.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("range::empty", "[range]")
{
  using int_vector = std::vector<int>;

  int_vector const vec1{1, 2};

  CHECK(fcppt::range::empty(fcppt::iterator::make_range(vec1.begin(), vec1.begin())));

  CHECK_FALSE(fcppt::range::empty(fcppt::iterator::make_range(vec1.begin(), vec1.end())));
}

FCPPT_CATCH_END

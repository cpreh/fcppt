//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/dynamic_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

template class fcppt::container::dynamic_array<int>;

FCPPT_CATCH_BEGIN

TEST_CASE("container::dynamic_array", "[container]")
{
  using int_array = fcppt::container::dynamic_array<int>;

  int_array array1{10};

  CHECK(std::distance(array1.data(), array1.data_end()) == 10);

  CHECK(array1.size() == 10U);

  int_array const array2{0};

  CHECK(array2.size() == 0U);
}

FCPPT_CATCH_END

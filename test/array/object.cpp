//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/get.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

template class fcppt::array::object<int,2U>;

FCPPT_CATCH_BEGIN

TEST_CASE("array::array", "[array]")
{
  fcppt::array::object<int,2U> const test{4,8};
  static_assert(test.size() == 2U);

  CHECK(fcppt::array::get<0>(test) == 4);
  CHECK(test.get_unsafe(0) == 4);
  CHECK(fcppt::array::get<1>(test) == 8);
  CHECK(test.get_unsafe(1) == 8);
  CHECK(test.begin() + 2U == test.end());
  CHECK(test.data() == &*test.begin());

  constexpr fcppt::array::object<int,1U> const c1{1};
  static_assert(fcppt::array::get<0>(c1) == 1);

  fcppt::array::object<int,1U> test2{c1};
  fcppt::array::get<0>(test2) = 10;
  CHECK(fcppt::array::get<0>(test2) == 10);
  CHECK(test2.begin() + 1U == test2.end());
  CHECK(test2.data() == &*test2.begin());
  CHECK(test2.size() == 1U);
}

FCPPT_CATCH_END

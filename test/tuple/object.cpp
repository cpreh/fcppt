//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("tuple::object", "[tuple]")
{
  fcppt::tuple::object<int,std::string> const test{4,"test"};

  CHECK(fcppt::tuple::get<0>(test) == 4);
  CHECK(fcppt::tuple::get<1>(test) == std::string{"test"});

  constexpr fcppt::tuple::object<int> const c1{1};
  static_assert(fcppt::tuple::get<0>(c1) == 1);

  fcppt::tuple::object<int,std::string> test2{test};
  fcppt::tuple::get<0>(test2) = 10;
  CHECK(fcppt::tuple::get<0>(test2) == 10);
}

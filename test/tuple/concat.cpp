//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/concat.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("tuple::concat", "[tuple]")
{
  CHECK(fcppt::tuple::concat(
     fcppt::tuple::make(std::string{"test"},1),
	 fcppt::tuple::make(2L))
	 ==
	 fcppt::tuple::make(std::string{"test"},1,2L));

  using movable = fcppt::catch_::movable<int>;

  CHECK(fcppt::tuple::concat(
     fcppt::tuple::make(movable{1}),
	 fcppt::tuple::make(2L))
	 ==
	 fcppt::tuple::make(movable{1},2L));
}

FCPPT_CATCH_END

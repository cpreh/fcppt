//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("make_unique_ptr", "[smartptr]")
{
  using int_ptr = fcppt::unique_ptr<int>;

  int_ptr const test1(fcppt::make_unique_ptr<int>(42));

  CHECK(*test1 == 42);
}

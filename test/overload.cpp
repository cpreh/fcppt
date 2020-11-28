//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/overload.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("overload", "[various]")
{
  auto const function{fcppt::overload([](bool) { return 0; }, [](int) { return 1; })};

  CHECK(function(true) == 0);

  CHECK(function(0) == 1);
}

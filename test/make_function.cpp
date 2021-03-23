//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/function.hpp>
#include <fcppt/make_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
int function(int const _value) { return _value + 1; }

}

TEST_CASE("make_function", "[various]")
{
  using int_function = fcppt::function<int(int)>;

  int_function const func{fcppt::make_function(function)};

  CHECK(func(10) == 11);
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_recursive.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/recursive_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("recursive", "[various]") { CHECK(fcppt::make_recursive(1) == fcppt::make_recursive(1)); }

TEST_CASE("recursive copy", "[various]")
{
  CHECK(fcppt::recursive<int>{fcppt::make_recursive(1)}.get() == 1);

  fcppt::recursive<int> value{2};

  value = fcppt::make_recursive(3);

  CHECK(value.get() == 3);

  fcppt::recursive<std::string> const value2{std::string{"test"}};
  CHECK(value2->size() == 4U);
}

FCPPT_CATCH_END

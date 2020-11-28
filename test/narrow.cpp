//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/narrow.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("narrow", "[string]")
{
  std::wstring const test{};

  CHECK(fcppt::narrow(test) == fcppt::optional_std_string{std::string{}});
}

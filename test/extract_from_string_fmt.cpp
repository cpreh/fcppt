//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/extract_from_string_fmt.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ios>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("extract_from_string", "[string]")
{
  using opt_bool = fcppt::optional::object<bool>;

  CHECK(
      fcppt::extract_from_string_fmt<bool>(std::string{"true"}, std::ios_base::boolalpha) ==
      opt_bool{true});
  CHECK(
      fcppt::extract_from_string_fmt<bool>(std::string{"false"}, std::ios_base::boolalpha) ==
      opt_bool{false});

  CHECK(fcppt::extract_from_string_fmt<bool>(std::string{"0"}, std::ios_base::boolalpha) == opt_bool{});
}

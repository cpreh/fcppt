//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <exception>
#include <stdexcept>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("either::try_call", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  auto const translate_exception(
      [](std::exception const &_error) { return std::string{_error.what()}; });

  CHECK(
      fcppt::either::try_call<std::exception>([] { return 42; }, translate_exception) ==
      either_int{42});

  CHECK(fcppt::either::try_call<std::exception>(
            []() -> int { throw std::runtime_error{"test"}; }, translate_exception)
            .has_failure());
}

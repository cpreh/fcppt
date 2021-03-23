//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/throw_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
bool contains_string(fcppt::string const &_string, fcppt::string const &_sub_string)
{
  return _string.find( // NOLINT(fuchsia-default-arguments-calls)
             _sub_string) != fcppt::string::npos;
}

}

TEST_CASE("assert_throw_message", "[assert]")
{
  auto const contains_false([](fcppt::assert_::exception const &_error) {
    return contains_string(_error.string(), FCPPT_TEXT("false"));
  });

  CHECK_THROWS_MATCHES(
      [] { FCPPT_ASSERT_THROW_MESSAGE(false, fcppt::assert_::exception, FCPPT_TEXT("test")); }(),
      fcppt::assert_::exception,
      Catch::Matchers::Predicate< // NOLINT(fuchsia-default-arguments-calls)
          fcppt::assert_::exception>(contains_false));

  CHECK_THROWS_MATCHES(
      [] { FCPPT_ASSERT_THROW_MESSAGE(false, fcppt::assert_::exception, FCPPT_TEXT("1337")); }(),
      fcppt::assert_::exception,
      Catch::Matchers::Predicate< // NOLINT(fuchsia-default-arguments-calls)
          fcppt::assert_::exception>([contains_false](fcppt::assert_::exception const &_error) {
        return contains_false(_error) && contains_string(_error.string(), FCPPT_TEXT("1337"));
      }));
}

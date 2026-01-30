//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_stream_error.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // IWYU pragma: keep
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::fatal", "[parse]")
{
  auto const parser{fcppt::parse::make_fatal(fcppt::parse::char_{})};

  CHECK(fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{}),
      [](fcppt::parse::parse_string_error<char> const &_string_error) -> bool
      {
        return fcppt::optional::maybe(
            _string_error.stream_error(),
            fcppt::const_(false),
            [](fcppt::parse::parse_stream_error<char> const &_stream_error)
            {
              return fcppt::variant::match(
                  _stream_error.get(),
                  [](fcppt::parse::error<char> const &_error) { return _error.is_fatal(); },
                  [](std::string const &) { return false; });
            });
      },
      [](auto const &) { return false; }));

  CHECK(
      fcppt::parse::parse_string(parser, std::string{"X"}) ==
      fcppt::parse::make_parse_string_success<char>('X'));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STRING_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/parse/parse_stream_error_fwd.hpp>
#include <fcppt/parse/parse_stream_error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/parse_string_error_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::parse_string_error<Ch> const &_error)
{
  fcppt::optional::maybe(
      _error.stream_error(),
      [&_stream, &_error]
      {
        fcppt::optional::maybe(
            _error.rest(),
            [&_stream]
            { _stream << FCPPT_STRING_LITERAL(Ch, "Unable to get remaining input of a string!"); },
            [&_stream](std::basic_string<Ch> const &_rest)
            {
              _stream << FCPPT_STRING_LITERAL(Ch, "Failed to consume remaining input:\n") << _rest
                      << FCPPT_CHAR_LITERAL(Ch, '\n');
            });
      },
      [&_stream, &_error](fcppt::parse::parse_stream_error<Ch> const &_stream_error)
      {
        _stream << _stream_error;

        fcppt::optional::maybe_void(
            _error.rest(),
            [&_stream](std::basic_string<Ch> const &_rest)
            {
              _stream << FCPPT_STRING_LITERAL(Ch, "\nRemaining input:\n") << _rest
                      << FCPPT_CHAR_LITERAL(Ch, '\n');
            });
      });

  return _stream;
}

}

#endif

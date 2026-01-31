//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STREAM_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STREAM_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/stream_error.hpp>
#include <fcppt/parse/stream_error_output.hpp> // IWYU pragma: keep
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::parse_stream_error<Ch> const &_error)
{
  fcppt::variant::match(
    _error.get(),
    [&_stream](fcppt::parse::error<Ch> const &_inner_error)
    {
      _stream << _inner_error;
    },
    [&_stream](fcppt::parse::stream_error const _stream_error)
    {
      _stream << _stream_error;
    });

  return _stream;
}

}

#endif

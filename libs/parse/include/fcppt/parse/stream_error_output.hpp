//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_STREAM_ERROR_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_STREAM_ERROR_OUTPUT_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/parse/stream_error.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::stream_error const _error)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch(_error)
  {
  case fcppt::parse::stream_error::tellg_failed:
    return _stream << FCPPT_STRING_LITERAL(Ch, "tellg failed.");
  case fcppt::parse::stream_error::seekg_failed:
    return _stream << FCPPT_STRING_LITERAL(Ch, "seekg failed.");
  case fcppt::parse::stream_error::bad_stream:
    return _stream << FCPPT_STRING_LITERAL(Ch, "Bad stream.");
  }
  FCPPT_PP_POP_WARNING
  return _stream << FCPPT_STRING_LITERAL(Ch, "Invalid stream error.");
}
}

#endif

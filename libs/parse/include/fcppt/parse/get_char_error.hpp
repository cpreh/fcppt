//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GET_CHAR_ERROR_HPP_INCLUDED
#define FCPPT_PARSE_GET_CHAR_ERROR_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The next character in a stream. Returns the error message "EOF" on failure.
\ingroup fcpptparse
*/
template <typename Ch>
fcppt::parse::result<Ch, Ch>
get_char_error(fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state)
{
  return fcppt::either::from_optional(fcppt::parse::get_char(_state), [] {
    return fcppt::parse::error<Ch>{std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "EOF")}};
  });
}

}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_STRING_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_STRING_IMPL_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/get_char_error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/skipper/basic_string_decl.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::skipper::basic_string<Ch>::basic_string(std::basic_string<Ch> &&_string)
    : string_{std::move(_string)}
{
}

template <typename Ch>
fcppt::parse::skipper::result<Ch>
fcppt::parse::skipper::basic_string<Ch>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  for (Ch const elem : this->string_)
  {
    if (fcppt::parse::get_char_error(_state) != fcppt::parse::result<Ch,Ch>(elem))
    {
      return fcppt::parse::skipper::make_failure(
          fcppt::parse::error<Ch>{FCPPT_STRING_LITERAL(Ch, "Expected ") + this->string_});
    }
  }

  return fcppt::parse::skipper::make_success<Ch>();
}

#endif

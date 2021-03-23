//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STRING_HPP_INCLUDED

#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Parses a <code>std::basic_string</code> without whitespace skipping.

\ingroup fcpptparse

Calls #fcppt::parse::phrase_parse_string with #fcppt::parse::skipper::epsilon.
*/
template <typename Ch, typename Parser>
[[nodiscard]] inline fcppt::parse::result<Ch, fcppt::parse::result_of<Parser>>
parse_string(Parser const &_parser, std::basic_string<Ch> &&_string)
{
  return fcppt::parse::phrase_parse_string(
      _parser, std::move(_string), fcppt::parse::skipper::epsilon());
}

}
}

#endif

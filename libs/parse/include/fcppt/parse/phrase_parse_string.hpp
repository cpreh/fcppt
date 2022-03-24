//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PHRASE_PARSE_STRING_HPP_INCLUDED
#define FCPPT_PARSE_PHRASE_PARSE_STRING_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/parse/error_add.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/phrase_parse_stream.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/consume_remaining.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parses a <code>std::basic_string</code>, using whitespace skipping.
\ingroup fcpptparse

\see fcppt::parse::phrase_parse
*/
template <
    typename Ch,
    typename Parser,
    typename Skipper,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::parse::is_parser<Parser>,
        fcppt::parse::skipper::is_skipper<Skipper>>>>
[[nodiscard]] fcppt::parse::result<Ch, fcppt::parse::result_of<Parser>>
phrase_parse_string(Parser const &_parser, std::basic_string<Ch> &&_string, Skipper const &_skipper)
{
  std::basic_istringstream<Ch> stream{std::move(_string)};

  stream.unsetf(std::ios_base::skipws);

  return fcppt::parse::detail::consume_remaining(
      fcppt::reference_to_base<std::basic_istream<Ch>>(fcppt::make_ref(stream)),
      fcppt::parse::phrase_parse_stream(_parser, stream, _skipper));
}
}

#endif

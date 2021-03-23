//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PHRASE_PARSE_HPP_INCLUDED
#define FCPPT_PARSE_PHRASE_PARSE_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/parse/skipper/run.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The basic parse function.
\ingroup fcpptparse

First, the skipper \a _skipper is called.
If this succeeds, then the result of parsing \a _input with \a _parser and \a _skipper is returned.
This function also catches all exceptions produced by \a _input and returns them as an error.
*/
template <
    typename Ch,
    typename Parser,
    typename Skipper,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::parse::is_parser<Parser>,
        fcppt::parse::skipper::is_skipper<Skipper>>>>
[[nodiscard]] inline fcppt::parse::result<Ch, fcppt::parse::result_of<Parser>>
phrase_parse(Parser const &_parser, fcppt::parse::basic_stream<Ch> &_input, Skipper const &_skipper)
try
{
  return fcppt::either::bind(
      fcppt::parse::skipper::run(_skipper, fcppt::make_ref(_input)),
      [&_parser, &_input, &_skipper](fcppt::unit const &) {
        return _parser.parse(fcppt::make_ref(_input), _skipper);
      });
}
catch (fcppt::parse::detail::exception<Ch> const &_error)
{
  return fcppt::either::make_failure<fcppt::parse::result_of<Parser>>(fcppt::parse::error<Ch>{
      std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "Parsing failed: ")} + _error.what()});
}
}
}

#endif

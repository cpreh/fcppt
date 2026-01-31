//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PHRASE_PARSE_HPP_INCLUDED
#define FCPPT_PARSE_PHRASE_PARSE_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/exception.hpp>
#include <fcppt/parse/detail/translate_exception.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/parse/skipper/run.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief The basic parse function.
\ingroup fcpptparse

First, the skipper \a _skipper is called.
If this succeeds, then the result of parsing \a _input with \a _parser and \a _skipper is returned.
This function also catches all exceptions produced by \a _input and returns them as an error.
*/
template <typename Ch, typename Parser, typename Skipper>
[[nodiscard]] inline fcppt::either::object<
    fcppt::parse::parse_stream_error<Ch>,
    fcppt::parse::result_of<Parser>>
phrase_parse(Parser const &_parser, fcppt::parse::basic_stream<Ch> &_input, Skipper const &_skipper)
  requires(std::conjunction_v<
           fcppt::parse::is_parser<Parser>,
           fcppt::parse::skipper::is_skipper<Skipper>>)
try
{
  return fcppt::either::map_failure(
      fcppt::either::bind(
          fcppt::parse::skipper::run(_skipper, fcppt::make_ref(_input)),
          [&_parser, &_input, &_skipper](fcppt::either::no_error const &)
          { return _parser.parse(fcppt::make_ref(_input), _skipper); }),
      [](fcppt::parse::error<Ch> &&_error)
      { return fcppt::parse::parse_stream_error<Ch>{std::move(_error)}; });
}
catch (fcppt::parse::detail::exception const &_error)
{
  return fcppt::parse::detail::translate_exception<fcppt::parse::result_of<Parser>, Ch>(_error);
}
}

#endif

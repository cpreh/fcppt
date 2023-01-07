//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PHRASE_PARSE_STREAM_HPP_INCLUDED
#define FCPPT_PARSE_PHRASE_PARSE_STREAM_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/parse/parse_stream_error_impl.hpp>
#include <fcppt/parse/phrase_parse.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/stream_impl.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parses a <code>std::basic_istream</code>, using whitespace skipping.
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
[[nodiscard]] fcppt::either::object<
    fcppt::parse::parse_stream_error<Ch>,
    fcppt::parse::result_of<Parser>>
phrase_parse_stream(Parser const &_parser, std::basic_istream<Ch> &_input, Skipper const &_skipper)
{
  fcppt::parse::detail::stream<Ch> stream{fcppt::make_ref(_input)};

  return fcppt::parse::phrase_parse(_parser, stream, _skipper);
}
}

#endif

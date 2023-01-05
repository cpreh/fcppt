//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GRAMMAR_PARSE_STREAM_HPP_INCLUDED
#define FCPPT_PARSE_GRAMMAR_PARSE_STREAM_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/grammar.hpp>
#include <fcppt/parse/parse_stream_error.hpp>
#include <fcppt/parse/phrase_parse_stream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parse a stream using a grammar.
\ingroup fcpptparse
*/
template <typename Result, typename Ch, typename Skipper>
[[nodiscard]] fcppt::either::object<fcppt::parse::parse_stream_error<Ch>, Result>
grammar_parse_stream(
    std::basic_istream<Ch> &_stream, fcppt::parse::grammar<Result, Ch, Skipper> const &_grammar)
{
  return fcppt::parse::phrase_parse_stream(*_grammar.start(), _stream, _grammar.skipper());
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GRAMMAR_PARSE_STRING_HPP_INCLUDED
#define FCPPT_PARSE_GRAMMAR_PARSE_STRING_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>
#include <fcppt/parse/grammar.hpp>
#include <fcppt/parse/parse_string_error_impl.hpp>
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Parse a string using a grammar.
\ingroup fcpptparse
*/
template <typename Result, typename Ch, typename Skipper>
fcppt::either::object<fcppt::parse::parse_string_error<Ch>, Result> grammar_parse_string(
    std::basic_string<Ch> &&_string, fcppt::parse::grammar<Result, Ch, Skipper> const &_grammar)
{
  return fcppt::parse::phrase_parse_string(
      *_grammar.start(), std::move(_string), _grammar.skipper());
}

}

#endif

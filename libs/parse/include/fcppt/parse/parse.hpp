//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_HPP_INCLUDED

#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/phrase_parse.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>

namespace fcppt::parse
{
/**
\brief Parses without whitespace skipping.

\ingroup fcpptparse

Calls #fcppt::parse::phrase_parse with #fcppt::parse::skipper::epsilon.
*/
template <typename Ch, typename Parser>
[[nodiscard]] inline fcppt::parse::result<Ch, fcppt::parse::result_of<Parser>>
parse(Parser const &_parser, fcppt::parse::basic_stream<Ch> &_input)
{
  return fcppt::parse::phrase_parse(_parser, _input, fcppt::parse::skipper::epsilon());
}

}

#endif

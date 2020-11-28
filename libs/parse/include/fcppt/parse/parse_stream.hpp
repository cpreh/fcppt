//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_PARSE_STREAM_HPP_INCLUDED
#define FCPPT_PARSE_PARSE_STREAM_HPP_INCLUDED

#include <fcppt/parse/phrase_parse_stream.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
template <typename Ch, typename Parser, typename Skipper>
[[nodiscard]] inline fcppt::parse::result<Ch, fcppt::parse::result_of<Parser>>
parse_stream(Parser const &_parser, std::basic_istream<Ch> &_input)
{
  return fcppt::parse::phrase_parse_stream(_parser, _input, fcppt::parse::skipper::epsilon());
}

}
}

#endif

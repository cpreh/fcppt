//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LOCATION_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_LOCATION_OUTPUT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/parse/location_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Outputs a location to a stream.
\ingroup fcpptparse
*/
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::location const &_loc)
{
  return _stream << _loc.line() << FCPPT_CHAR_LITERAL(Ch, ':') << _loc.column();
}

}
}

#endif

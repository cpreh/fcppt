//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_POSITION_OUTPUT_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_OUTPUT_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/parse/location_output.hpp>
#include <fcppt/parse/position_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Outputs a position to a stream.
\ingroup fcpptparse
*/
template <typename Ch>
std::basic_ostream<Ch> &
operator<<(std::basic_ostream<Ch> &_stream, fcppt::parse::position<Ch> const &_pos)
{
  return _stream << _pos.pos() << FCPPT_STRING_LITERAL(Ch, ", ") << _pos.location();
}

}
}

#endif

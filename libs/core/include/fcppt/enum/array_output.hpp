//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_OUTPUT_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_OUTPUT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/output.hpp>
#include <fcppt/enum/array_impl.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Outputs an enum array.

\ingroup fcpptenum
*/
template <typename Ch, typename Traits, typename Enum, typename Value>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::enum_::array<Enum, Value> const &_array)
  requires(fcppt::enum_::is_object<Enum>::value)
{
  _stream << FCPPT_CHAR_LITERAL(Ch, '[');

  for (Enum const value : fcppt::enum_::make_range<Enum>())
  {
    _stream << fcppt::io::widen_string(std::string{fcppt::enum_::to_string(value)})
            << FCPPT_CHAR_LITERAL(Ch, '=') << fcppt::output(_array[value]);
    if (value != fcppt::enum_::max_value<Enum>::value)
    {
      _stream << FCPPT_CHAR_LITERAL(Ch, ',');
    }
  }

  _stream << FCPPT_CHAR_LITERAL(Ch, ']');

  return _stream;
}
}

#endif

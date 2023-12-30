//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_OUTPUT_HPP_INCLUDED
#define FCPPT_ENUM_OUTPUT_HPP_INCLUDED

#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Outputs an enum value to a stream.

\ingroup fcpptenum

Uses #fcppt::enum_::to_string to output \a _value to \a _stream.
This function is useful to implement <code>operator<<</code> for an enum type.

\tparam Enum Must be an enum type

\return \a _stream
*/
template <
    typename Ch,
    typename Traits,
    typename Enum,
    typename = std::enable_if<fcppt::enum_::is_object<Enum>::value>>
std::basic_ostream<Ch, Traits> &output(std::basic_ostream<Ch, Traits> &_stream, Enum const _value)
{
  return _stream << fcppt::io::widen_string(std::string{fcppt::enum_::to_string(_value)});
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_INPUT_HPP_INCLUDED
#define FCPPT_ENUM_INPUT_HPP_INCLUDED

#include <fcppt/enum/from_string.hpp>
#include <fcppt/enum/is_object.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/io/narrow_string.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <istream>
#include <string>
#include <string_view>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Reads an enum value from a stream.

\ingroup fcpptenum

Uses #fcppt::enum_::from_string to read an enum from \a _stream
and store it in \a _result. In case this fails, the failbit of \a _stream is set.
This function is useful to implement <code>operator>></code> for an enum type.

\tparam Enum Must be an enum type

\return \a _stream
*/
template <
    typename Ch,
    typename Traits,
    typename Enum,
    typename = std::enable_if_t<fcppt::enum_::is_object<Enum>::value>>
std::basic_istream<Ch, Traits> &input(std::basic_istream<Ch, Traits> &_stream, Enum &_result)
{
  fcppt::optional::maybe(
      fcppt::optional::bind(
          fcppt::io::extract<std::basic_string<Ch, Traits>>(_stream),
          [&_stream](std::basic_string<Ch, Traits> const &_value)
          {
            return fcppt::optional::bind(
                fcppt::io::narrow_string(_stream, std::basic_string_view<Ch, Traits>{_value}),
                [](std::string const &_string) { return fcppt::enum_::from_string<Enum>(_string); });
          }),
      [&_stream] { _stream.setstate(std::ios_base::failbit); },
      [&_result](Enum const _arg) { _result = _arg; });

  return _stream;
}
}

#endif

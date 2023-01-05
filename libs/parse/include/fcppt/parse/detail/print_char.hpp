//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_PRINT_CHAR_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_PRINT_CHAR_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::detail
{
template <typename Ch>
inline void print_char(std::basic_ostream<Ch> &_stream, fcppt::optional::object<Ch> const &_opt_ch)
{
  fcppt::optional::maybe(
      _opt_ch,
      [&_stream] { _stream << FCPPT_STRING_LITERAL(Ch, "EOF"); },
      [&_stream](Ch const _ch) { _stream << _ch; });
}
}

#endif

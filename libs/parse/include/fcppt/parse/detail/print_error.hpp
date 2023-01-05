//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_PRINT_ERROR_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_PRINT_ERROR_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/parse/alternative_error_impl.hpp>
#include <fcppt/parse/basic_char_error_impl.hpp>
#include <fcppt/parse/basic_char_set_error_impl.hpp>
#include <fcppt/parse/basic_literal_error_impl.hpp>
#include <fcppt/parse/basic_string_error_impl.hpp>
#include <fcppt/parse/complement_error_impl.hpp>
#include <fcppt/parse/custom_error_impl.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/fail_error_impl.hpp>
#include <fcppt/parse/named_error_impl.hpp>
#include <fcppt/parse/position_output.hpp>
#include <fcppt/parse/typed_error_impl.hpp>
#include <fcppt/parse/detail/print_char.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt::parse::detail
{

template<typename Ch>
void print_error(std::basic_ostream<Ch> &_stream, fcppt::parse::error<Ch> const &_error, unsigned const _indent)
{
  // TODO(philipp): This is also needed in fcppt.options.
  auto const indent{[&_stream, _indent] { _stream << std::basic_string<Ch>(_indent, ' '); }};
  unsigned const extra_indent{_indent + 2U};

  fcppt::variant::match(
      _error.get(),
      [&_stream, indent, extra_indent](fcppt::parse::alternative_error<Ch> const &_inner)
      {
        fcppt::parse::detail::print_error(_stream, _inner.left().get(), extra_indent);
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "\nor\n");
        fcppt::parse::detail::print_error(_stream, _inner.right().get(), extra_indent);
      },
      [&_stream, indent](fcppt::parse::basic_char_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "EOF reached at ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, indent](fcppt::parse::basic_char_set_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": Expected {")
                << fcppt::container::output(_inner.chars()) << FCPPT_STRING_LITERAL(Ch, "}, got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, indent](fcppt::parse::basic_literal_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": Expected ") << _inner.expected()
                << FCPPT_STRING_LITERAL(Ch, ", got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, indent](fcppt::parse::basic_string_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": Expected ") << _inner.expected()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, indent](fcppt::parse::complement_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": Expected any but {")
                << fcppt::container::output(_inner.chars()) << FCPPT_STRING_LITERAL(Ch, "}, got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, indent](fcppt::parse::custom_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": ")
                << _inner.message()
                << FCPPT_STRING_LITERAL(Ch, "\n");
      },
      [&_stream, indent](fcppt::parse::fail_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": FAIL.\n");
      },
      [&_stream, indent, extra_indent](fcppt::parse::named_error<Ch> const &_inner)
      {
        indent();
        _stream << _inner.name() << FCPPT_STRING_LITERAL(Ch, ":\n");
        fcppt::parse::detail::print_error(_stream, _inner.error().get(), extra_indent);
      },
      [&_stream, indent](fcppt::parse::typed_error<Ch> const &_inner)
      {
        indent();
        _stream << FCPPT_STRING_LITERAL(Ch, "At ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ": Expected type ") << _inner.type_name()
                << FCPPT_STRING_LITERAL(Ch, ", got ") << _inner.got()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      });
}

}

#endif

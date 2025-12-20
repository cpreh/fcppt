//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DETAIL_PRINT_ERROR_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_PRINT_ERROR_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/indent/extra.hpp>
#include <fcppt/indent/level.hpp>
#include <fcppt/indent/print.hpp>
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
#include <fcppt/parse/position_output.hpp> // IWYU pragma: keep
#include <fcppt/parse/typed_error_impl.hpp>
#include <fcppt/parse/detail/print_char.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt::parse::detail
{

template <typename Ch>
void print_error(
    std::basic_ostream<Ch> &_stream,
    fcppt::parse::error<Ch> const &_error,
    fcppt::indent::level const _indent)
{
  fcppt::variant::match(
      _error.get(),
      [&_stream, _indent](fcppt::parse::alternative_error<Ch> const &_inner)
      {
        fcppt::parse::detail::print_error(
            _stream, _inner.left().get(), fcppt::indent::extra(_indent));
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "or\n");
        fcppt::parse::detail::print_error(
            _stream, _inner.right().get(), fcppt::indent::extra(_indent));
      },
      [&_stream, _indent](fcppt::parse::basic_char_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent)
                << FCPPT_STRING_LITERAL(Ch, "EOF reached at ") << _inner.pos()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, _indent](fcppt::parse::basic_char_set_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": Expected ")
                << fcppt::container::output(_inner.chars()) << FCPPT_STRING_LITERAL(Ch, ", got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, _indent](fcppt::parse::basic_literal_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": Expected ") << _inner.expected()
                << FCPPT_STRING_LITERAL(Ch, ", got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, _indent](fcppt::parse::basic_string_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": Expected ") << _inner.expected()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, _indent](fcppt::parse::complement_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": Expected any but ")
                << fcppt::container::output(_inner.chars()) << FCPPT_STRING_LITERAL(Ch, ", got ");
        fcppt::parse::detail::print_char(_stream, _inner.got());
        _stream << FCPPT_STRING_LITERAL(Ch, ".\n");
      },
      [&_stream, _indent](fcppt::parse::custom_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": ") << _inner.message()
                << FCPPT_STRING_LITERAL(Ch, "\n");
      },
      [&_stream, _indent](fcppt::parse::fail_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": FAIL.\n");
      },
      [&_stream, _indent](fcppt::parse::named_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << _inner.name()
                << FCPPT_STRING_LITERAL(Ch, ":\n");
        fcppt::parse::detail::print_error(
            _stream, _inner.error().get(), fcppt::indent::extra(_indent));
      },
      [&_stream, _indent](fcppt::parse::typed_error<Ch> const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_STRING_LITERAL(Ch, "At ")
                << _inner.pos() << FCPPT_STRING_LITERAL(Ch, ": Expected type ")
                << _inner.type_name() << FCPPT_STRING_LITERAL(Ch, ", got ") << _inner.got()
                << FCPPT_STRING_LITERAL(Ch, ".\n");
      });
}
}

#endif

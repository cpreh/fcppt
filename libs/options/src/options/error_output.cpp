//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/detail/indent/extra.hpp>
#include <fcppt/detail/indent/level.hpp>
#include <fcppt/detail/indent/print.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/options/argument_conversion_error.hpp>
#include <fcppt/options/dual_flag_error.hpp>
#include <fcppt/options/dual_option_error.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_pair.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/leftover_error.hpp>
#include <fcppt/options/invalid_command_error.hpp>
#include <fcppt/options/missing_argument_error.hpp>
#include <fcppt/options/missing_command_error.hpp>
#include <fcppt/options/missing_flag_error.hpp>
#include <fcppt/options/missing_option_argument_error.hpp>
#include <fcppt/options/missing_option_error.hpp>
#include <fcppt/options/option_conversion_error.hpp>
#include <fcppt/options/impl/long_or_short_name.hpp>
#include <fcppt/variant/match.hpp>

namespace
{
void print_error(
    fcppt::io::ostream &_stream,
    fcppt::options::error const &_error,
    fcppt::detail::indent::level const _indent)
{
  fcppt::variant::match(
      _error.get(),
      [&_stream, _indent](fcppt::options::argument_conversion_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Failed to convert \"")
                << _inner.arg() << FCPPT_TEXT("\" to ") << _inner.type_name()
                << FCPPT_TEXT(" for argument \"") << _inner.long_name() << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::dual_flag_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Both the short flag name ")
                << _inner.short_name() << FCPPT_TEXT(" and the long flag name ")
                << _inner.long_name() << FCPPT_TEXT(" were specified at the same time.");
      },
      [&_stream, _indent](fcppt::options::dual_option_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent)
                << FCPPT_TEXT("Both the short option name ") << _inner.short_name()
                << FCPPT_TEXT(" and the long option name ") << _inner.long_name()
                << FCPPT_TEXT(" were specified at the same time.");
      },
      [&_stream, _indent](fcppt::options::error_pair const &_inner)
      {
        print_error(_stream, _inner.left().get(), fcppt::detail::indent::extra(_indent));
        _stream << FCPPT_TEXT('\n');
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT('|');
        _stream << FCPPT_TEXT('\n');
        print_error(_stream, _inner.right().get(), fcppt::detail::indent::extra(_indent));
      },
      [&_stream, _indent](fcppt::options::leftover_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Leftover arguments ")
                << fcppt::container::output(_inner.args()) << FCPPT_TEXT('.');
      },
      [&_stream, _indent](fcppt::options::invalid_command_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Invalid command \"")
                << _inner.command() << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::missing_argument_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Missing argument \"")
                << _inner.long_name() << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::missing_command_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("No command specified from ")
                << fcppt::container::output(_inner.commands()) << FCPPT_TEXT(".");
      },
      [&_stream, _indent](fcppt::options::missing_flag_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Missing flag \"")
                << fcppt::options::impl::long_or_short_name(
                       _inner.long_name(), _inner.short_name())
                << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::missing_option_argument_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Missing option for \"")
                << _inner.name() << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::missing_option_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Missing option \"")
                << fcppt::options::impl::long_or_short_name(
                       _inner.long_name(), _inner.short_name())
                << FCPPT_TEXT("\".");
      },
      [&_stream, _indent](fcppt::options::option_conversion_error const &_inner)
      {
        _stream << fcppt::detail::indent::print(_indent) << FCPPT_TEXT("Failed to convert \"")
                << _inner.arg() << FCPPT_TEXT("\" to ") << _inner.type_name()
                << FCPPT_TEXT(" for option \"") << _inner.name() << FCPPT_TEXT("\".");
      });
}
}

fcppt::io::ostream &
fcppt::options::operator<<(fcppt::io::ostream &_stream, fcppt::options::error const &_error)
{
  print_error(_stream, _error, fcppt::detail::indent::level{0U});
  return _stream;
}

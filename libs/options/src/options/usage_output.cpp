//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/indent/extra.hpp>
#include <fcppt/indent/level.hpp>
#include <fcppt/indent/print.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/commands_usage.hpp>
#include <fcppt/options/flag_usage.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/many_usage.hpp>
#include <fcppt/options/option_usage.hpp>
#include <fcppt/options/optional_usage.hpp>
#include <fcppt/options/product_usage.hpp>
#include <fcppt/options/sub_command_usage.hpp>
#include <fcppt/options/sum_usage.hpp>
#include <fcppt/options/unit_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_output.hpp>
#include <fcppt/options/impl/help_text.hpp>
#include <fcppt/options/impl/long_or_short_name.hpp>
#include <fcppt/options/impl/type_annotation.hpp>
#include <fcppt/variant/match.hpp>

namespace
{
void print_usage(
    fcppt::io::ostream &_stream,
    fcppt::options::usage const &_usage,
    fcppt::indent::level const _indent)
{
  fcppt::variant::match(
      _usage.get(),
      [&_stream, _indent](fcppt::options::argument_usage const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << _inner.long_name()
                << fcppt::options::impl::type_annotation(_inner.type())
                << fcppt::options::impl::help_text(_inner.help_text());
      },
      [&_stream, _indent](fcppt::options::commands_usage const &_inner)
      {
        print_usage(_stream, _inner.options_usage().get(), _indent);

        _stream << FCPPT_TEXT('\n');

        for (fcppt::options::sub_command_usage const &sub_command : _inner.sub_commands())
        {
          fcppt::indent::level const extra_indent{fcppt::indent::extra(_indent)};

          _stream << fcppt::indent::print(extra_indent) << sub_command.name()
                  << FCPPT_TEXT(": ");

          fcppt::optional::maybe_void(
              sub_command.help_text(),
              [&_stream](fcppt::options::help_text const &_help_text)
              { _stream << FCPPT_TEXT(" (") << _help_text << FCPPT_TEXT(')'); });

          fcppt::io::ostringstream inner_output{};

          print_usage(inner_output, sub_command.inner().get(), extra_indent);

          fcppt::string const inner_usage{inner_output.str()};

          if (fcppt::not_(inner_usage.empty()))
          {
            _stream << FCPPT_TEXT('\n') << inner_usage << FCPPT_TEXT('\n');
          }
        }
      },
      [&_stream, _indent](fcppt::options::flag_usage const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_TEXT("[ ")
                << fcppt::options::impl::long_or_short_name(
                       _inner.long_name(), _inner.short_name())
                << FCPPT_TEXT(" ]") << fcppt::options::impl::help_text(_inner.help_text());
      },
      [&_stream, _indent](fcppt::options::many_usage const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_TEXT("[ ");

        print_usage(_stream, _inner.inner().get(), _indent);

        _stream << fcppt::indent::print(_indent) << FCPPT_TEXT(" ]*");
      },
      [&_stream, _indent](fcppt::options::option_usage const &_inner)
      {
        _stream << fcppt::indent::print(_indent);

        if (_inner.default_value().has_value())
        {
          _stream << FCPPT_TEXT("[ ");
        }

        _stream << fcppt::options::impl::long_or_short_name(
                       _inner.long_name(), _inner.short_name())
                << fcppt::options::impl::type_annotation(_inner.type());

        fcppt::optional::maybe_void(
            _inner.default_value(),
            [&_stream](fcppt::string const &_value) { _stream << FCPPT_TEXT(" / ") + _value; });

        if (_inner.default_value().has_value())
        {
          _stream << FCPPT_TEXT(" ]");
        }

        _stream << fcppt::options::impl::help_text(_inner.help_text());
      },
      [&_stream, _indent](fcppt::options::optional_usage const &_inner)
      {
         _stream << fcppt::indent::print(_indent) << FCPPT_TEXT("[ ");
         print_usage(_stream, _inner.inner().get(), _indent);
         _stream << fcppt::indent::print(_indent) << FCPPT_TEXT(" ]");
      },
      [&_stream, _indent](fcppt::options::product_usage const &_inner)
      {
        print_usage(_stream, _inner.left().get(), _indent);
        _stream << FCPPT_TEXT('\n');
        print_usage(_stream, _inner.right().get(), _indent);
      },
      [&_stream, _indent](fcppt::options::sum_usage const &_inner)
      {
        _stream << fcppt::indent::print(_indent) << FCPPT_TEXT("(\n");

        print_usage(_stream, _inner.left().get(), fcppt::indent::extra(_indent));

        _stream << FCPPT_TEXT('\n') << fcppt::indent::print(_indent) << FCPPT_TEXT("|\n");

        print_usage(_stream, _inner.right().get(), fcppt::indent::extra(_indent));

        _stream << FCPPT_TEXT("\n)");
      },
      [](fcppt::options::unit_usage const &) {});
}
}

fcppt::io::ostream &
fcppt::options::operator<<(fcppt::io::ostream &_stream, fcppt::options::usage const &_usage)
{
  print_usage(_stream, _usage, fcppt::indent::level{0U});
  return _stream;
}

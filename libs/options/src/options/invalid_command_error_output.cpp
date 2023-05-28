//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/options/invalid_command_error.hpp>
#include <fcppt/options/invalid_command_error_output.hpp>

fcppt::io::ostream &fcppt::options::operator<<(
    fcppt::io::ostream &_stream, fcppt::options::invalid_command_error const &_error)
{
  return _stream << FCPPT_TEXT("Invalid command \"") << _error.command() << FCPPT_TEXT("\".");
}

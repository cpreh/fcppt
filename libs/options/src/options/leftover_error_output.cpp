//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/options/leftover_error.hpp>
#include <fcppt/options/leftover_error_output.hpp>

fcppt::io::ostream &fcppt::options::operator<<(
    fcppt::io::ostream &_stream, fcppt::options::leftover_error const &_error)
{
  return _stream << FCPPT_TEXT("Leftover arguments ")
                 << fcppt::output_to_fcppt_string(fcppt::container::output(_error.args()))
                 << FCPPT_TEXT('.');
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/options/dual_flag_error.hpp>
#include <fcppt/options/dual_flag_error_output.hpp>

fcppt::io::ostream &fcppt::options::operator<<(
    fcppt::io::ostream &_stream, fcppt::options::dual_flag_error const &_error)
{
  return _stream << FCPPT_TEXT("Both the short flag name ") << _error.short_name()
                 << FCPPT_TEXT(" and the long flag name ") << _error.long_name()
                 << FCPPT_TEXT(" were specified at the same time.");
}

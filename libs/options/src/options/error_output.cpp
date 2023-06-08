//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/options/argument_conversion_error_output.hpp>
#include <fcppt/options/dual_flag_error_output.hpp>
#include <fcppt/options/dual_option_error_output.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_pair_output.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/leftover_error_output.hpp>
#include <fcppt/options/invalid_command_error_output.hpp>
#include <fcppt/options/missing_argument_error_output.hpp>
#include <fcppt/options/missing_command_error_output.hpp>
#include <fcppt/options/missing_flag_error_output.hpp>
#include <fcppt/options/missing_option_argument_error_output.hpp>
#include <fcppt/options/missing_option_error_output.hpp>
#include <fcppt/options/option_conversion_error_output.hpp>
#include <fcppt/variant/output.hpp>

fcppt::io::ostream &
fcppt::options::operator<<(fcppt::io::ostream &_stream, fcppt::options::error const &_error)
{
  // TODO(philipp)
  return _stream << _error.get();
}

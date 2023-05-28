//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TEST_OPTIONS_CATCH_OUTPUT_HPP_INCLUDED
#define FCPPT_TEST_OPTIONS_CATCH_OUTPUT_HPP_INCLUDED

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/options/argument_conversion_error.hpp>
#include <fcppt/options/argument_conversion_error_output.hpp>
#include <fcppt/options/dual_flag_error.hpp>
#include <fcppt/options/dual_flag_error_output.hpp>
#include <fcppt/options/dual_option_error.hpp>
#include <fcppt/options/dual_option_error_output.hpp>
#include <fcppt/options/error_pair.hpp>
#include <fcppt/options/error_pair_output.hpp>
#include <fcppt/options/leftover_error.hpp>
#include <fcppt/options/leftover_error_output.hpp>
#include <fcppt/options/invalid_command_error.hpp>
#include <fcppt/options/invalid_command_error_output.hpp>
#include <fcppt/options/missing_argument_error.hpp>
#include <fcppt/options/missing_argument_error_output.hpp>
#include <fcppt/options/missing_command_error.hpp>
#include <fcppt/options/missing_command_error_output.hpp>
#include <fcppt/options/missing_flag_error.hpp>
#include <fcppt/options/missing_flag_error_output.hpp>
#include <fcppt/options/missing_option_argument_error.hpp>
#include <fcppt/options/missing_option_argument_error_output.hpp>
#include <fcppt/options/missing_option_error.hpp>
#include <fcppt/options/missing_option_error_output.hpp>
#include <fcppt/options/option_conversion_error.hpp>
#include <fcppt/options/option_conversion_error_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
#define FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt_type) \
template <> \
struct StringMaker<fcppt_type> \
{ \
  static std::string convert(fcppt_type const &_value)\
  { \
    return fcppt::catch_::convert(fcppt::output_to_fcppt_string(_value)); \
  } \
}

FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::argument_conversion_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::dual_flag_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::dual_option_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::error_pair);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::leftover_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::invalid_command_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::missing_argument_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::missing_command_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::missing_flag_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::missing_option_argument_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::missing_option_error);
FCPPT_TEST_OPTIONS_DEFINE_CONVERT(fcppt::options::option_conversion_error);

}

#endif

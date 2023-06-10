//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/main.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)

int FCPPT_MAIN(int argc, fcppt::args_char **argv)
try
{
  // ![options_help_int]
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using parser_type = fcppt::options::argument<arg_label, int>;

  parser_type const parser{
      fcppt::options::long_name{FCPPT_TEXT("arg1")},
      fcppt::options::optional_help_text{
          fcppt::options::help_text{FCPPT_TEXT("The main argument")}}};
  // ![options_help_int]

  // ![options_parse_help]
  fcppt::options::help_result<fcppt::options::result_of<parser_type>> const result{
      fcppt::options::parse_help(
          fcppt::options::default_help_switch(), parser, fcppt::args_from_second(argc, argv))};
  // ![options_parse_help]

  // ![options_help_match]
  fcppt::variant::match(
      result,
      [](fcppt::options::result<fcppt::options::result_of<parser_type>> const &_result) {
        fcppt::io::cout() << _result << FCPPT_TEXT('\n');
      },
      [](fcppt::options::usage const &_usage) {
        fcppt::io::cout() << _usage << FCPPT_TEXT('\n');
      });
  // ![options_help_match]

  return EXIT_SUCCESS;
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}

FCPPT_PP_POP_WARNING

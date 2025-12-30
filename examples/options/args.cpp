//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/main.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/apply.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/usage_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
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
  FCPPT_RECORD_MAKE_LABEL(arg1_label);
  FCPPT_RECORD_MAKE_LABEL(arg2_label);

  using result_type = fcppt::record::
      object<fcppt::record::element<arg1_label, int>, fcppt::record::element<arg2_label, int>>;

  auto const parser{fcppt::options::apply(
      fcppt::options::argument<arg1_label, int>{
          fcppt::options::long_name{FCPPT_TEXT("int1")},
          fcppt::options::optional_help_text{
              fcppt::options::help_text{FCPPT_TEXT("First operand")}}},
      fcppt::options::argument<arg2_label, int>{
          fcppt::options::long_name{FCPPT_TEXT("int2")},
          fcppt::options::optional_help_text{
              fcppt::options::help_text{FCPPT_TEXT("Second operand")}}})};

  fcppt::args_vector const args{fcppt::args_from_second(argc, argv)};

  fcppt::options::result<result_type> const result{fcppt::options::parse(parser, args)};

  return fcppt::either::match(
      result,
      [&parser](fcppt::options::error const &_error)
      {
        fcppt::io::cerr() << _error << FCPPT_TEXT('\n') << FCPPT_TEXT("Usage:\n") << parser.usage()
                          << FCPPT_TEXT('\n');

        return EXIT_FAILURE;
      },
      [](result_type const &_result)
      {
        fcppt::io::cout() << FCPPT_TEXT("The result is ")
                          << (fcppt::record::get<arg1_label>(_result) +
                              fcppt::record::get<arg2_label>(_result))
                          << FCPPT_TEXT('\n');

        return EXIT_SUCCESS;
      });
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}

FCPPT_PP_POP_WARNING

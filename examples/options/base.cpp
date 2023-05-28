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
#include <fcppt/options/apply.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/base.hpp>
#include <fcppt/options/base_unique_ptr.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_base.hpp>
#include <fcppt/options/make_many.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/switch.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/output.hpp>
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
  // ![options_base_record]
  FCPPT_RECORD_MAKE_LABEL(int_arg_label);
  FCPPT_RECORD_MAKE_LABEL(switch_label);

  using result_type = fcppt::record::object<
      fcppt::record::element<int_arg_label, int>,
      fcppt::record::element<switch_label, bool>>;
  // ![options_base_record]

  // ![options_create_base]
  auto const create_base([]() -> fcppt::options::base_unique_ptr<result_type> {
    return fcppt::options::make_base<result_type>(fcppt::options::apply(
        fcppt::options::argument<int_arg_label, int>{
            fcppt::options::long_name{FCPPT_TEXT("arg")}, fcppt::options::optional_help_text{}},
        fcppt::options::switch_<switch_label>{
            fcppt::options::optional_short_name{},
            fcppt::options::long_name{FCPPT_TEXT("switch")},
            fcppt::options::optional_help_text{}}));
  });
  // ![options_create_base]

  // ![options_use_base]
  fcppt::options::base_unique_ptr<result_type> const base{create_base()};

  fcppt::options::result<result_type> const result{
      fcppt::options::parse(*base, fcppt::args_from_second(argc, argv))};
  // ![options_use_base]

  fcppt::io::cout() << result << FCPPT_TEXT('\n');

  // ![options_base_combine]
  auto const combined{fcppt::options::make_many(create_base())};
  // ![options_base_combine]

  fcppt::io::cout()
      << fcppt::options::parse(combined, fcppt::args_from_second(argc, argv)).has_success()
      << FCPPT_TEXT('\n');

  return EXIT_SUCCESS;
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}

FCPPT_PP_POP_WARNING

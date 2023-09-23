//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

// TODO(philipp): Output openmode properly
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-promo)

#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/main.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/filesystem/ifstream.hpp>
#include <fcppt/filesystem/ofstream.hpp>
#include <fcppt/filesystem/open_exn.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_input.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/level_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/level_to_string_impl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/apply.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_optional.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/pretty_type_enum.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/switch.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_output.hpp>
#include <fcppt/record/are_equivalent_v.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <ios>
#include <iostream>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)

int FCPPT_MAIN(int argc, fcppt::args_char **argv)
try
{
  // ![options_labels]
  FCPPT_RECORD_MAKE_LABEL(input_file_label);
  FCPPT_RECORD_MAKE_LABEL(output_file_label);
  FCPPT_RECORD_MAKE_LABEL(execute_label);
  FCPPT_RECORD_MAKE_LABEL(openmode_label);
  FCPPT_RECORD_MAKE_LABEL(log_level_label);
  // ![options_labels]

  // ![options_input_file_option]
  using input_file_option = fcppt::options::argument<input_file_label, fcppt::string>;

  input_file_option const input_file{
      fcppt::options::long_name{FCPPT_TEXT("Input filename")},
      fcppt::options::optional_help_text{
          fcppt::options::help_text{FCPPT_TEXT("The name of the input file to copy")}}};
  // ![options_input_file_option]

  // ![options_output_file_option]
  using output_file_option = fcppt::options::argument<output_file_label, fcppt::string>;

  using optional_output_file_option = fcppt::options::optional<output_file_option>;

  optional_output_file_option const output_file{fcppt::options::make_optional(output_file_option{
      fcppt::options::long_name{FCPPT_TEXT("Output filename")},
      fcppt::options::optional_help_text{fcppt::options::help_text{
          FCPPT_TEXT("The name of the output file. Defaults to input_file.bak")}}})};
  // ![options_output_file_option]

  // ![options_execute_switch]
  using execute_switch = fcppt::options::switch_<execute_label>;

  execute_switch const execute{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("e")}},
      fcppt::options::long_name{FCPPT_TEXT("execute")},
      fcppt::options::optional_help_text{
          fcppt::options::help_text{FCPPT_TEXT("Whether to actually execute the actions")}}};
  // ![options_execute_switch]

  // ![options_openmode_option]
  using openmode_option = fcppt::options::flag<openmode_label, std::ios_base::openmode>;

  openmode_option const openmode{
      fcppt::options::optional_short_name{},
      fcppt::options::long_name{FCPPT_TEXT("trunc")},
      openmode_option::active_value{std::ios_base::trunc},
      openmode_option::inactive_value{std::ios_base::openmode{}},
      fcppt::options::optional_help_text{
          fcppt::options::help_text{FCPPT_TEXT("Whether to truncate the output file")}}};
  // ![options_openmode_option]

  // ![options_log_level_option]
  using log_level_option = fcppt::options::option<log_level_label, fcppt::log::level>;

  log_level_option const log_level{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("l")}},
      fcppt::options::long_name{FCPPT_TEXT("loglevel")},
      log_level_option::optional_default_value{fcppt::optional::make(fcppt::log::level::warning)},
      fcppt::options::optional_help_text{
          fcppt::options::help_text{FCPPT_TEXT("The log level to use")}}};
  // ![options_log_level_option]

  // ![options_parser]
  auto const parser(fcppt::options::apply(
      fcppt::make_cref(input_file),
      fcppt::make_cref(output_file),
      fcppt::make_cref(execute),
      fcppt::make_cref(openmode),
      fcppt::make_cref(log_level)));
  // ![options_parser]

  // ![options_result_type]
  using result_type = fcppt::options::result_of<decltype(parser)>;

  static_assert(
      fcppt::record::are_equivalent_v<
          result_type,
          fcppt::record::object<
              fcppt::record::element<input_file_label, fcppt::string>,
              fcppt::record::element<output_file_label, fcppt::optional::object<fcppt::string>>,
              fcppt::record::element<execute_label, bool>,
              fcppt::record::element<openmode_label, std::ios_base::openmode>,
              fcppt::record::element<log_level_label, fcppt::log::level>>>);
  // ![options_result_type]

  // ![options_main_program]
  auto const main_program([](result_type const &_result) -> bool {
    // ![options_main_program]

    // ![options_read_execute]
    if (!fcppt::record::get<execute_label>(_result))
    {
      return false;
    }
    // ![options_read_execute]

    // ![options_log_context]
    fcppt::log::context log_context{
        fcppt::log::optional_level{fcppt::record::get<log_level_label>(_result)},
        fcppt::log::default_level_streams()};
    // ![options_log_context]

    fcppt::log::object const logger{
        fcppt::make_ref(log_context),
        fcppt::log::parameters{
            fcppt::log::name{FCPPT_TEXT("options")}, fcppt::log::format::optional_function{}}};

    // ![options_open_input]
    fcppt::filesystem::ifstream const input{fcppt::filesystem::open_exn<fcppt::filesystem::ifstream>(
        fcppt::record::get<input_file_label>(_result),
        std::ios_base::openmode{})};
    // ![options_open_input]

    // ![options_output_filename]
    fcppt::string const output_filename{
        fcppt::optional::from(fcppt::record::get<output_file_label>(_result), [&_result] {
          return fcppt::record::get<input_file_label>(_result) + FCPPT_TEXT(".bak");
        })};
    // ![options_output_filename]

    // ![options_open_output]
    fcppt::filesystem::ofstream const output{fcppt::filesystem::open_exn<fcppt::filesystem::ofstream>(
        output_filename,
        fcppt::record::get<openmode_label>(_result))};
    // ![options_open_output]

    // ...

    return true;
  });

  return fcppt::variant::match(
      fcppt::options::parse_help(
          fcppt::options::default_help_switch(), parser, fcppt::args_from_second(argc, argv)),
      [main_program](fcppt::options::result<result_type> const &_result) {
        return fcppt::either::match(
            _result,
            [](fcppt::options::error const &_error) {
              fcppt::io::cerr() << _error << FCPPT_TEXT('\n');

              return EXIT_FAILURE;
            },
            [main_program](result_type const &_options) {
              if (!main_program(_options))
              {
                fcppt::io::cout() << FCPPT_TEXT("The result is:\n") << _options << FCPPT_TEXT('\n');
              }

              return EXIT_SUCCESS;
            });
      },
      [](fcppt::options::usage const &_usage) {
        fcppt::io::cout() << _usage << FCPPT_TEXT('\n');

        return EXIT_SUCCESS;
      });
}
catch (fcppt::exception const &_exception)
{
  fcppt::io::cerr() << _exception.string() << FCPPT_TEXT('\n');

  return EXIT_FAILURE;
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}

FCPPT_PP_POP_WARNING
FCPPT_PP_POP_WARNING

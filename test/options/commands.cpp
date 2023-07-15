//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/commands_usage.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_commands.hpp>
#include <fcppt/options/make_sub_command.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/option_usage.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/options/sub_command_usage.hpp>
#include <fcppt/options/unit.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/test/options/catch_error.hpp>
#include <fcppt/test/options/catch_usage.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::commands", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  FCPPT_RECORD_MAKE_LABEL(option_label);

  FCPPT_RECORD_MAKE_LABEL(command_foo_label);

  FCPPT_RECORD_MAKE_LABEL(command_bar_label);

  using int_arg = fcppt::options::argument<arg_label, int>;

  using int_option = fcppt::options::option<option_label, int>;

  auto const commands{fcppt::options::make_commands(
      int_option{
          fcppt::options::optional_short_name{},
          fcppt::options::long_name{FCPPT_TEXT("option")},
          fcppt::options::no_default_value<int>(),
          fcppt::options::optional_help_text{}},
      fcppt::options::make_sub_command<command_foo_label>(
          FCPPT_TEXT("foo"),
          int_arg{
              fcppt::options::long_name{FCPPT_TEXT("arg1")}, fcppt::options::optional_help_text{}},
          fcppt::options::optional_help_text{}),
      fcppt::options::make_sub_command<command_bar_label>(
          FCPPT_TEXT("bar"),
          int_option{
              fcppt::options::optional_short_name{},
              fcppt::options::long_name{FCPPT_TEXT("option")},
              fcppt::options::no_default_value<int>(),
              fcppt::options::optional_help_text{}},
          fcppt::options::optional_help_text{}))};

  using result_type = fcppt::options::result_of<decltype(commands)>;

  using command_foo_result_type =
      fcppt::record::object<fcppt::record::element<command_foo_label, int_arg::result_type>>;

  using command_bar_result_type =
      fcppt::record::object<fcppt::record::element<command_bar_label, int_option::result_type>>;

  using command_result_type =
      fcppt::variant::object<command_foo_result_type, command_bar_result_type>;

  CHECK(
      fcppt::options::parse(
          commands,
          fcppt::args_vector{
              FCPPT_TEXT("--option"), FCPPT_TEXT("10"), FCPPT_TEXT("foo"), FCPPT_TEXT("0")}) ==
      fcppt::options::make_success(result_type{
          fcppt::options::options_label{} = int_option::result_type{option_label{} = 10},
          fcppt::options::sub_command_label{} = command_result_type{command_foo_result_type{
              command_foo_label{} = int_arg::result_type{arg_label{} = 0}}}}));

  CHECK(
      fcppt::options::parse(
          commands,
          fcppt::args_vector{
              FCPPT_TEXT("--option"),
              FCPPT_TEXT("10"),
              FCPPT_TEXT("bar"),
              FCPPT_TEXT("--option"),
              FCPPT_TEXT("0")}) ==
      fcppt::options::make_success(result_type{
          fcppt::options::options_label{} = int_option::result_type{option_label{} = 10},
          fcppt::options::sub_command_label{} = command_result_type{command_bar_result_type{
              command_bar_label{} = int_option::result_type{option_label{} = 0}}}}));

  CHECK(fcppt::options::parse(
            commands,
            fcppt::args_vector{
                FCPPT_TEXT("test"),
            })
            .has_failure());

  CHECK(fcppt::options::parse(
            commands,
            fcppt::args_vector{
                FCPPT_TEXT("foo"),
                FCPPT_TEXT("0"),
            })
            .has_failure());

  CHECK(fcppt::options::parse(
            commands,
            fcppt::args_vector{
                FCPPT_TEXT("--option"),
                FCPPT_TEXT("10"),
                FCPPT_TEXT("foo"),
            })
            .has_failure());

  CHECK(
      commands.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::commands_usage{
          fcppt::make_recursive(
              fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::option_usage{
                  fcppt::options::option_usage::default_value_type{
                      fcppt::optional::object<fcppt::string>{}},
                  fcppt::options::long_name{FCPPT_TEXT("option")},
                  fcppt::options::optional_short_name{},
                  fcppt::options::pretty_type<int>(),
                  fcppt::options::optional_help_text{}}}}),
          fcppt::container::make<std::vector<fcppt::options::sub_command_usage>>(
              fcppt::options::sub_command_usage{
                  FCPPT_TEXT("foo"),
                  fcppt::make_recursive(fcppt::options::usage{
                      fcppt::options::usage_variant{fcppt::options::argument_usage{
                          fcppt::options::long_name{FCPPT_TEXT("arg1")},
                          fcppt::options::pretty_type<int>(),
                          fcppt::options::optional_help_text{}}}}),
                  fcppt::options::optional_help_text{}},
              fcppt::options::sub_command_usage{
                  FCPPT_TEXT("bar"),
                  fcppt::make_recursive(fcppt::options::usage{
                      fcppt::options::usage_variant{fcppt::options::option_usage{
                          fcppt::options::option_usage::default_value_type{
                              fcppt::optional::object<fcppt::string>{}},
                          fcppt::options::long_name{FCPPT_TEXT("option")},
                          fcppt::options::optional_short_name{},
                          fcppt::options::pretty_type<int>(),
                          fcppt::options::optional_help_text{}}}}),
                  fcppt::options::optional_help_text{}})}}});
}

TEST_CASE("options::commands duplicate names", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(unit_label);

  FCPPT_RECORD_MAKE_LABEL(command_1_label);

  FCPPT_RECORD_MAKE_LABEL(command_2_label);

  CHECK_THROWS_AS(
      fcppt::options::make_commands(
          fcppt::options::unit<unit_label>{},
          fcppt::options::make_sub_command<command_1_label>(
              FCPPT_TEXT("foo"),
              fcppt::options::unit<unit_label>{},
              fcppt::options::optional_help_text{}),
          fcppt::options::make_sub_command<command_2_label>(
              FCPPT_TEXT("foo"),
              fcppt::options::unit<unit_label>{},
              fcppt::options::optional_help_text{})
              ),
      fcppt::options::duplicate_names);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

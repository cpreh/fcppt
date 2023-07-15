//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/apply.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/flag_usage.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_active_value.hpp>
#include <fcppt/options/make_inactive_value.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/product_usage.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp>
#include <fcppt/test/options/catch_usage.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::apply", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using int_arg_type = fcppt::options::argument<arg_label, int>;

  FCPPT_RECORD_MAKE_LABEL(flag_label);

  using int_flag_type = fcppt::options::flag<flag_label, int>;

  auto const mult_parser(fcppt::options::apply(
      int_arg_type{
          fcppt::options::long_name{FCPPT_TEXT("arg1")}, fcppt::options::optional_help_text{}},
      int_flag_type{
          fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
          fcppt::options::long_name{FCPPT_TEXT("flag")},
          fcppt::options::make_active_value(42),
          fcppt::options::make_inactive_value(10),
          fcppt::options::optional_help_text{}}));

  CHECK(
      fcppt::options::parse(
          mult_parser, fcppt::args_vector{FCPPT_TEXT("--flag"), FCPPT_TEXT("123")}) ==
      fcppt::options::make_success(
          decltype(mult_parser)::result_type{arg_label{} = 123, flag_label{} = 42}));

  CHECK(
      mult_parser.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::product_usage{
          fcppt::make_recursive(
              fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::argument_usage{
                  fcppt::options::long_name{FCPPT_TEXT("arg1")},
                  fcppt::options::pretty_type<int>(),
                  fcppt::options::optional_help_text{}}}}),
          fcppt::make_recursive(
              fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::flag_usage{
                  fcppt::options::long_name{FCPPT_TEXT("flag")},
                  fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
                  fcppt::options::optional_help_text{}}}})}}});
}

TEST_CASE("options::apply duplicate names", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(flag_label1);

  FCPPT_RECORD_MAKE_LABEL(flag_label2);

  using flag1_type = fcppt::options::flag<flag_label1, int>;

  using flag2_type = fcppt::options::flag<flag_label2, int>;

  CHECK_THROWS_AS(
      fcppt::options::apply(
          flag1_type{
              fcppt::options::optional_short_name{},
              fcppt::options::long_name{FCPPT_TEXT("flag")},
              fcppt::options::make_active_value(0),
              fcppt::options::make_inactive_value(1),
              fcppt::options::optional_help_text{}},
          flag2_type{
              fcppt::options::optional_short_name{},
              fcppt::options::long_name{FCPPT_TEXT("flag")},
              fcppt::options::make_active_value(0),
              fcppt::options::make_inactive_value(1),
              fcppt::options::optional_help_text{}}),
      fcppt::options::duplicate_names);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

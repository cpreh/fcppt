//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_default_value.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/option_usage.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/pretty_type.hpp>
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

TEST_CASE("options::option", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using int_option_type = fcppt::options::option<arg_label, int>;

  int_option_type const int_option{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
      fcppt::options::long_name{FCPPT_TEXT("option")},
      fcppt::options::no_default_value<int>(),
      fcppt::options::optional_help_text{}};

  CHECK(
      fcppt::options::parse(int_option, fcppt::args_vector{FCPPT_TEXT("-f"), FCPPT_TEXT("42")}) ==
      fcppt::options::make_success(int_option_type::result_type{arg_label{} = 42}));

  CHECK(
      fcppt::options::parse(
          int_option, fcppt::args_vector{FCPPT_TEXT("--option"), FCPPT_TEXT("42")}) ==
      fcppt::options::make_success(int_option_type::result_type{arg_label{} = 42}));

  CHECK(fcppt::options::parse(
            int_option, fcppt::args_vector{FCPPT_TEXT("-something"), FCPPT_TEXT("42")})
            .has_failure());

  CHECK(
      fcppt::options::parse(int_option, fcppt::args_vector{FCPPT_TEXT("--option")}).has_failure());

  CHECK(fcppt::options::parse(int_option, fcppt::args_vector{FCPPT_TEXT("--flag")}).has_failure());

  CHECK(
      int_option.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::option_usage{
          fcppt::options::option_usage::default_value_type{
              fcppt::optional::object<fcppt::string>{}},
          fcppt::options::long_name{FCPPT_TEXT("option")},
          fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
          fcppt::options::pretty_type<int>(),
          fcppt::options::optional_help_text{}}}});

  int_option_type const int_option_with_default{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
      fcppt::options::long_name{FCPPT_TEXT("option")},
      fcppt::options::make_default_value(fcppt::optional::make(100)),
      fcppt::options::optional_help_text{}};

  CHECK(
      fcppt::options::parse(
          int_option_with_default, fcppt::args_vector{FCPPT_TEXT("-f"), FCPPT_TEXT("42")}) ==
      fcppt::options::make_success(int_option_type::result_type{arg_label{} = 42}));

  CHECK(fcppt::options::parse(int_option_with_default, fcppt::args_vector{FCPPT_TEXT("--option")})
            .has_failure());

  CHECK(
      fcppt::options::parse(int_option_with_default, fcppt::args_vector{}) ==
      fcppt::options::make_success(int_option_type::result_type{arg_label{} = 100}));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

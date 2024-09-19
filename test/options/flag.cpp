//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/variant.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/exception.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/flag_usage.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_active_value.hpp>
#include <fcppt/options/make_inactive_value.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/test/options/catch_usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::flag", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using int_flag_type = fcppt::options::flag<arg_label, int>;

  int_flag_type const int_flag{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
      fcppt::options::long_name{FCPPT_TEXT("flag")},
      fcppt::options::make_active_value(42),
      fcppt::options::make_inactive_value(10),
      fcppt::options::optional_help_text{}};

  CHECK(
      fcppt::options::parse(int_flag, fcppt::args_vector{FCPPT_TEXT("-f")}) ==
      fcppt::options::make_success(int_flag_type::result_type{arg_label{} = 42}));

  CHECK(
      fcppt::options::parse(int_flag, fcppt::args_vector{FCPPT_TEXT("--flag")}) ==
      fcppt::options::make_success(int_flag_type::result_type{arg_label{} = 42}));

  CHECK(
      fcppt::options::parse(int_flag, fcppt::args_vector{}) ==
      fcppt::options::make_success(int_flag_type::result_type{arg_label{} = 10}));

  CHECK(
      int_flag.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::flag_usage{
          fcppt::options::long_name{FCPPT_TEXT("flag")},
          fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
          fcppt::options::optional_help_text{}}}});

  CHECK_THROWS_AS(
      int_flag_type(
          fcppt::options::optional_short_name{},
          fcppt::options::long_name{FCPPT_TEXT("flag")},
          fcppt::options::make_active_value(0),
          fcppt::options::make_inactive_value(0),
          fcppt::options::optional_help_text{}),
      fcppt::options::exception);
}

TEST_CASE("options::flag duplicate names", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(flag_label);

  using flag_type = fcppt::options::flag<flag_label, int>;

  CHECK_THROWS_AS(
      flag_type(
          fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("flag")}},
          fcppt::options::long_name{FCPPT_TEXT("flag")},
          fcppt::options::make_active_value(0),
          fcppt::options::make_inactive_value(1),
          fcppt::options::optional_help_text{}),
      fcppt::options::duplicate_names);
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

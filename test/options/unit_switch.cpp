//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/unit_output.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp> // IWYU pragma: keep
#include <fcppt/catch/strong_typedef.hpp> // IWYU pragma: keep
#include <fcppt/catch/variant.hpp> // IWYU pragma: keep
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/flag_usage.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/unit_switch.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/comparison.hpp> // IWYU pragma: keep
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp> // IWYU pragma: keep
#include <fcppt/test/options/catch_usage.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::unit_switch", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(dummy_label);

  using switch_type = fcppt::options::unit_switch<dummy_label>;

  using result_type = fcppt::options::result_of<switch_type>;

  switch_type const switch_{
      fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
      fcppt::options::long_name{FCPPT_TEXT("flag")},
      fcppt::options::optional_help_text{}};

  CHECK(
      fcppt::options::parse(switch_, fcppt::args_vector{FCPPT_TEXT("-f")}) ==
      fcppt::options::make_success(result_type{dummy_label{} = fcppt::unit{}}));

  CHECK(
      fcppt::options::parse(switch_, fcppt::args_vector{FCPPT_TEXT("--flag")}) ==
      fcppt::options::make_success(result_type{dummy_label{} = fcppt::unit{}}));

  CHECK(fcppt::options::parse(switch_, fcppt::args_vector{}).has_failure());

  CHECK(
      switch_.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::flag_usage{
          fcppt::options::long_name{FCPPT_TEXT("flag")},
          fcppt::options::optional_short_name{fcppt::options::short_name{FCPPT_TEXT("f")}},
          fcppt::options::optional_help_text{}}}});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

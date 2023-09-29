//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/unit_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/variant.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/flag_usage.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_left.hpp>
#include <fcppt/options/make_right.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/make_sum.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sum_usage.hpp>
#include <fcppt/options/unit_switch.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/test/options/catch_usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/variant/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::sum", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(label);

  FCPPT_RECORD_MAKE_LABEL(unit_label);

  using unit_parser = fcppt::options::unit_switch<unit_label>;

  auto const sum{fcppt::options::make_sum<label>(
      unit_parser{
          fcppt::options::optional_short_name{},
          fcppt::options::long_name{FCPPT_TEXT("left")},
          fcppt::options::optional_help_text{}},
      unit_parser{
          fcppt::options::optional_short_name{},
          fcppt::options::long_name{FCPPT_TEXT("right")},
          fcppt::options::optional_help_text{}})};

  using parser_type = decltype(sum);

  CHECK(
      fcppt::options::parse(sum, fcppt::args_vector{FCPPT_TEXT("--left")}) ==
      fcppt::options::make_success(fcppt::options::result_of<parser_type>{
          label{} = parser_type::variant{
              fcppt::options::make_left(fcppt::options::result_of<parser_type::left>(
                  fcppt::options::result_of<unit_parser>{unit_label{} = fcppt::unit{}}))}}));

  CHECK(
      fcppt::options::parse(sum, fcppt::args_vector{FCPPT_TEXT("--right")}) ==
      fcppt::options::make_success(fcppt::options::result_of<parser_type>{
          label{} = parser_type::variant{
              fcppt::options::make_right(fcppt::options::result_of<parser_type::right>(
                  fcppt::options::result_of<unit_parser>{unit_label{} = fcppt::unit{}}))}}));

  CHECK(fcppt::options::parse(sum, fcppt::args_vector{}).has_failure());

  CHECK(
      sum.usage() == fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::sum_usage{
                         fcppt::make_recursive(fcppt::options::usage{
                             fcppt::options::usage_variant{fcppt::options::flag_usage{
                                 fcppt::options::long_name{FCPPT_TEXT("left")},
                                 fcppt::options::optional_short_name{},
                                 fcppt::options::optional_help_text{}}}}),
                         fcppt::make_recursive(fcppt::options::usage{
                             fcppt::options::usage_variant{fcppt::options::flag_usage{
                                 fcppt::options::long_name{FCPPT_TEXT("right")},
                                 fcppt::options::optional_short_name{},
                                 fcppt::options::optional_help_text{}}}})}}});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

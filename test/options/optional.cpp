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
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_optional.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_usage.hpp>
#include <fcppt/options/parse.hpp>
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

TEST_CASE("options::optional", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  auto const parser{fcppt::options::make_optional(fcppt::options::argument<arg_label, int>{
      fcppt::options::long_name{FCPPT_TEXT("arg1")}, fcppt::options::optional_help_text{}})};

  using parser_type = decltype(parser);

  CHECK(
      fcppt::options::parse(parser, fcppt::args_vector{FCPPT_TEXT("123")}) ==
      fcppt::options::make_success(
          parser_type::result_type{arg_label{} = fcppt::optional::make(123)}));

  CHECK(fcppt::options::parse(parser, fcppt::args_vector{FCPPT_TEXT("test")}).has_failure());

  CHECK(
      fcppt::options::parse(parser, fcppt::args_vector{}) ==
      fcppt::options::make_success(
          parser_type::result_type{arg_label{} = fcppt::optional::nothing{}}));

  CHECK(
      parser.usage() ==
      fcppt::options::usage{
          fcppt::options::usage_variant{fcppt::options::optional_usage{fcppt::make_recursive(
              fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::argument_usage{
                  fcppt::options::long_name{FCPPT_TEXT("arg1")},
                  fcppt::options::pretty_type<int>(),
                  fcppt::options::optional_help_text{}}}})}}});
}

FCPPT_CATCH_END

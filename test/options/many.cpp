//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/variant.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_many.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/many_usage.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/test/options/catch_usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::many", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  auto const parser{fcppt::options::make_many(fcppt::options::argument<arg_label, int>{
      fcppt::options::long_name{FCPPT_TEXT("arg1")}, fcppt::options::optional_help_text{}})};

  using parser_type = decltype(parser);

  CHECK(
      fcppt::options::parse(parser, fcppt::args_vector{FCPPT_TEXT("123"), FCPPT_TEXT("456")}) ==
      fcppt::options::make_success(
          parser_type::result_type{arg_label{} = std::vector<int>{123, 456}}));

  CHECK(fcppt::options::parse(parser, fcppt::args_vector{FCPPT_TEXT("123"), FCPPT_TEXT("test")})
            .has_failure());

  CHECK(
      fcppt::options::parse(parser, fcppt::args_vector{}) ==
      fcppt::options::make_success(parser_type::result_type{arg_label{} = std::vector<int>{}}));

  CHECK(
      parser.usage() == fcppt::options::usage{fcppt::options::usage_variant{
                            fcppt::options::many_usage{fcppt::make_recursive(fcppt::options::usage{
                                fcppt::options::usage_variant{fcppt::options::argument_usage{
                                    fcppt::options::long_name{FCPPT_TEXT("arg1")},
                                    fcppt::options::pretty_type<int>(),
                                    fcppt::options::optional_help_text{}}}})}}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

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
#include <fcppt/either/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/record/comparison.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/record/make_label.hpp>
#include <fcppt/test/options/catch_error.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/test/options/catch_usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::parse_help", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using int_arg_type = fcppt::options::argument<arg_label, int>;

  int_arg_type const int_arg{
      fcppt::options::long_name{FCPPT_TEXT("arg1")}, fcppt::options::optional_help_text{}};

  CHECK(
      fcppt::options::parse_help(
          fcppt::options::default_help_switch(),
          int_arg,
          fcppt::args_vector{FCPPT_TEXT("--help")}) ==
      fcppt::options::help_result<fcppt::options::result_of<int_arg_type>>{int_arg.usage()});

  CHECK(
      fcppt::options::parse_help(
          fcppt::options::default_help_switch(), int_arg, fcppt::args_vector{FCPPT_TEXT("1")}) ==
      fcppt::options::help_result<fcppt::options::result_of<int_arg_type>>{
          fcppt::options::make_success(int_arg_type::result_type{arg_label{} = 1})});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

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
#include <fcppt/options/argument.hpp>
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/base_unique_ptr.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_base.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/test/options/catch_error.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/test/options/catch_usage.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("options::base", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(arg_label);

  using result_type = fcppt::record::object<fcppt::record::element<arg_label, int>>;

  fcppt::options::base_unique_ptr<result_type> const base{
      fcppt::options::make_base<result_type>(fcppt::options::argument<arg_label, int>{
          fcppt::options::long_name{FCPPT_TEXT("arg")}, fcppt::options::optional_help_text{}})};

  CHECK(
      fcppt::options::parse(*base, fcppt::args_vector{FCPPT_TEXT("123")}) ==
      fcppt::options::make_success(result_type{arg_label{} = 123}));

  CHECK(fcppt::options::parse(*base, fcppt::args_vector{FCPPT_TEXT("test")}).has_failure());

  CHECK(fcppt::options::parse(*base, fcppt::args_vector{}).has_failure());

  CHECK(
      base->usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::argument_usage{
          fcppt::options::long_name{FCPPT_TEXT("arg")},
          fcppt::options::pretty_type<int>(),
          fcppt::options::optional_help_text{}}}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

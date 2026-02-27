//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp> // IWYU pragma: keep
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/either.hpp> // IWYU pragma: keep
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/record.hpp> // IWYU pragma: keep
#include <fcppt/catch/strong_typedef.hpp> // IWYU pragma: keep
#include <fcppt/catch/variant.hpp> // IWYU pragma: keep
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp> // IWYU pragma: keep
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/leftover_error.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/unit.hpp>
#include <fcppt/options/unit_usage.hpp>
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

TEST_CASE("options::unit", "[options]")
{
  FCPPT_RECORD_MAKE_LABEL(dummy_label);

  using unit_type = fcppt::options::unit<dummy_label>;

  unit_type const unit{};

  CHECK(
      fcppt::options::parse(unit, fcppt::args_vector{}) ==
      fcppt::options::make_success(unit_type::result_type{dummy_label{} = fcppt::unit{}}));

  CHECK(
      fcppt::options::parse(unit, fcppt::args_vector{FCPPT_TEXT("")}) ==
      fcppt::either::make_failure<fcppt::options::result_of<unit_type>>(
          fcppt::options::error{fcppt::options::error_variant{
              fcppt::options::leftover_error{fcppt::args_vector{FCPPT_TEXT("")}}}}));

  CHECK(
      unit.usage() ==
      fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::unit_usage{}}});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/parse/make_parse_string_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("parse::base", "[parse]")
{
  fcppt::parse::base_unique_ptr<std::string, char, fcppt::parse::skipper::epsilon> const parser{
      fcppt::parse::make_base<char, fcppt::parse::skipper::epsilon>(*fcppt::parse::char_{})};

  CHECK(
      fcppt::parse::parse_string(*parser, std::string{"XY"}) ==
      fcppt::parse::make_parse_string_success<char>(std::string{"XY"}));

  CHECK(
      fcppt::parse::phrase_parse_string(
          *parser, std::string{"XY"}, fcppt::parse::skipper::epsilon()) ==
      fcppt::parse::make_parse_string_success<char>(std::string{"XY"}));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

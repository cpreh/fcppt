//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/split_string.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm_split_string"
          "[algorithm]")
{
  CHECK(
      fcppt::algorithm::split_string(std::string{""}, 'x') ==
      std::vector<std::string>{std::string{}});

  CHECK(
      fcppt::algorithm::split_string(std::string{"x"}, 'x') ==
      std::vector<std::string>{std::string{}, std::string{}});

  CHECK(
      fcppt::algorithm::split_string(std::string{"ax"}, 'x') ==
      std::vector<std::string>{std::string{"a"}, std::string{}});

  CHECK(
      fcppt::algorithm::split_string(std::string{"xa"}, 'x') ==
      std::vector<std::string>{std::string{}, std::string{"a"}});

  CHECK(
      fcppt::algorithm::split_string(std::string{"aaxbb"}, 'x') ==
      std::vector<std::string>{std::string{"aa"}, std::string{"bb"}});

  CHECK(
      fcppt::algorithm::split_string(std::string{"aaxbbxc"}, 'x') ==
      std::vector<std::string>{std::string{"aa"}, std::string{"bb"}, std::string{"c"}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/remove_suffix.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/optional.hpp> // IWYU pragma: keep
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm_remove_suffix", "[algorithm]")
{
  CHECK(
      fcppt::algorithm::remove_suffix(std::string{"abc"}, 4) ==
      fcppt::optional::object<std::string>{});

  CHECK(
      fcppt::algorithm::remove_suffix(std::string{"abc"}, 3) ==
      fcppt::optional::make(std::string{}));

  CHECK(
      fcppt::algorithm::remove_suffix(std::string{"abc"}, 2) ==
      fcppt::optional::make(std::string{"a"}));

  CHECK(
      fcppt::algorithm::remove_suffix(std::string{"abc"}, 1) ==
      fcppt::optional::make(std::string{"ab"}));

  CHECK(
      fcppt::algorithm::remove_suffix(std::string{"abc"}, 0) ==
      fcppt::optional::make(std::string{"abc"}));
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::apply", "[optiona;]")
{
  using optional_int = fcppt::optional::object<int>;

  using optional_unsigned = fcppt::optional::object<unsigned>;

  using optional_string = fcppt::optional::object<std::string>;

  CHECK(
      fcppt::optional::apply(
          [](int const _val1, unsigned const _val2) {
            return std::to_string(_val1) + std::to_string(_val2);
          },
          optional_int(10),
          optional_unsigned(20U)) == optional_string(std::string("1020")));

  CHECK(
      fcppt::optional::apply(
          [](int, unsigned) { return std::string{}; }, optional_int(), optional_unsigned(20)) ==
      optional_string());
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

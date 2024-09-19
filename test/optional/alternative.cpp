//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::alternative", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  CHECK(
      fcppt::optional::alternative(optional_int(42), fcppt::const_(optional_int(10))) ==
      optional_int(42));

  CHECK(
      fcppt::optional::alternative(optional_int(), fcppt::const_(optional_int(10))) ==
      optional_int(10));

  CHECK(
      fcppt::optional::alternative(optional_int(), fcppt::const_(optional_int())) ==
      optional_int());

  optional_int const value{};

  CHECK(fcppt::optional::alternative(value, fcppt::const_(optional_int{42})) == optional_int{42});
}

TEST_CASE("optional::alternative move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  CHECK(fcppt::optional::alternative(optional_int_movable{int_movable{42}}, [] {
          return optional_int_movable{};
        }) == optional_int_movable{int_movable{42}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

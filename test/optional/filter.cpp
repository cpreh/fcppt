//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/filter.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::filter", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  auto const function([](int const _value) { return _value == 1; });

  CHECK(fcppt::optional::filter(optional_int(1), function) == optional_int{1});

  CHECK(fcppt::optional::filter(optional_int(2), function) == optional_int{});

  CHECK(fcppt::optional::filter(optional_int(), function) == optional_int{});
}

TEST_CASE("optional::filter move", "[optional]")
{
  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  CHECK(
      fcppt::optional::filter(optional_int_movable(int_movable{42}), [](int_movable const &_value) {
        return _value.value() == 42;
      }) == optional_int_movable{int_movable{42}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

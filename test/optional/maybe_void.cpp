//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("optional::maybe_void", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  int result{0};

  fcppt::optional::maybe_void(optional_int(10), [&result](int const _val) { result = _val; });

  CHECK(result == 10);

  fcppt::optional::maybe_void(optional_int(), [&result](int const _val) { result = _val; });

  CHECK(result == 10);

  optional_int temp(0);

  fcppt::optional::maybe_void(temp, [](int &_val) { _val = 30; });

  CHECK(temp == optional_int(30));
}

TEST_CASE("optional::maybe_void ref", "[optional]")
{
  int result{0};

  using optional_int_ref = fcppt::optional::reference<int>;

  fcppt::optional::maybe_void(
      optional_int_ref{fcppt::make_ref(result)},
      [](fcppt::reference<int> const _val) { _val.get() = 1; });

  CHECK(result == 1);
}

TEST_CASE("optional::maybe_void move", "[optional]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using optional_int_unique_ptr = fcppt::optional::object<int_unique_ptr>;

  fcppt::optional::maybe_void(
      optional_int_unique_ptr(fcppt::make_unique_ptr<int>(1)),
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
      [](int_unique_ptr &&_ptr) { CHECK(*_ptr == 1); });
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

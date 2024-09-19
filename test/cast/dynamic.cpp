//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
struct base
{
  FCPPT_NONMOVABLE(base);

  base() = default;

  virtual ~base() = default;
};

struct derived1 : base
{
  FCPPT_NONMOVABLE(derived1);

  derived1() = default;

  ~derived1() override = default;
};

struct derived2 : base
{
  FCPPT_NONMOVABLE(derived2);

  derived2() = default;

  ~derived2() override = default;
};

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("cast::dynamic", "[cast]")
{
  derived1 d1{};

  derived2 d2{};

  base &b1{d1};

  base &b2{d2};

  CHECK(fcppt::cast::dynamic<derived1>(b1) == fcppt::optional::make(fcppt::make_ref(d1)));

  CHECK(
      fcppt::cast::apply<fcppt::cast::dynamic_fun, derived1>(b1) ==
      fcppt::optional::make(fcppt::make_ref(d1)));

  CHECK(
      fcppt::cast::dynamic<derived1>(b2) == fcppt::optional::object<fcppt::reference<derived1>>{});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/dynamic_any.hpp>
#include <fcppt/cast/dynamic_any_fun.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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

struct other
{
  FCPPT_NONMOVABLE(other);

  other() = default;

  virtual ~other() = default;
};

}

FCPPT_CATCH_BEGIN

TEST_CASE("cast::dynamic_any", "[cast]")
{
  derived1 d1{};

  other d2{};

  base &b1{d1};

  CHECK(fcppt::cast::dynamic_any<derived1>(b1) == fcppt::optional::make(fcppt::make_ref(d1)));

  CHECK(
      fcppt::cast::apply<fcppt::cast::dynamic_any_fun, derived1>(b1) ==
      fcppt::optional::make(fcppt::make_ref(d1)));

  CHECK(fcppt::cast::dynamic_any<other>(b1) == fcppt::optional::object<fcppt::reference<other>>{});
}

FCPPT_CATCH_END

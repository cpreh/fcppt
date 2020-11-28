//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/cast/dynamic_cross_exn.hpp>
#include <fcppt/cast/dynamic_cross_fun.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
struct derived1
{
  FCPPT_NONMOVABLE(derived1);

public:
  derived1() = default;

  virtual ~derived1() = default;
};

struct derived2
{
  FCPPT_NONMOVABLE(derived2);

public:
  virtual ~derived2() = default;
};

}

TEST_CASE("cast::dynamic_cross", "[cast]")
{
  derived1 d1{};

  CHECK(
      fcppt::cast::dynamic_cross<derived2>(d1) ==
      fcppt::optional::object<fcppt::reference<derived2>>{});

  CHECK(
      fcppt::cast::apply<fcppt::cast::dynamic_cross_fun, derived2>(d1) ==
      fcppt::optional::object<fcppt::reference<derived2>>{});

  CHECK_THROWS_AS(fcppt::cast::dynamic_cross_exn<derived2 &>(d1), fcppt::cast::bad_dynamic);
}

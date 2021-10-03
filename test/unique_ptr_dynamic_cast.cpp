//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/unique_ptr_dynamic_cast.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
class base
{
  FCPPT_NONMOVABLE(base);

public:
  base() = default;

  virtual ~base() = default;
};

class derived : public base
{
  FCPPT_NONMOVABLE(derived);

public:
  derived() : base() {}

  ~derived() override = default;
};

}

FCPPT_CATCH_BEGIN

TEST_CASE("unique_ptr_dynamic_cast", "[smartptr]")
{
  using base_unique_ptr = fcppt::unique_ptr<base>;

  using derived_unique_ptr = fcppt::unique_ptr<derived>;

  CHECK(fcppt::variant::holds_type<base_unique_ptr>(
      fcppt::unique_ptr_dynamic_cast<fcppt::cast::dynamic_fun, derived>(
          fcppt::make_unique_ptr<base>())));

  CHECK(fcppt::variant::holds_type<derived_unique_ptr>(
      fcppt::unique_ptr_dynamic_cast<fcppt::cast::dynamic_fun, derived>(
          fcppt::unique_ptr_to_base<base>(fcppt::make_unique_ptr<derived>()))));
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/dynamic_cast.hpp>
#include <fcppt/variant/from_list.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
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

class derived1 : public base
{
  FCPPT_NONMOVABLE(derived1);

public:
  derived1() = default;

  ~derived1() override = default;
};

class derived2 : public base
{
  FCPPT_NONMOVABLE(derived2);

public:
  derived2() = default;

  ~derived2() override = default;
};

class derived3 : public base
{
  FCPPT_NONMOVABLE(derived3);

public:
  derived3() = default;

  ~derived3() override = default;
};

}

TEST_CASE("variant::dynamic_cast", "[variant]")
{
  using derived_types = metal::list<derived1, derived2>;

  using result_variant =
      fcppt::variant::from_list<fcppt::variant::dynamic_cast_types<derived_types>>;

  using result_type = fcppt::optional::object<result_variant>;

  {
    derived1 d1{};

    base &base_ref{d1};

    result_type const result{
        fcppt::variant::dynamic_cast_<derived_types, fcppt::cast::dynamic_fun>(base_ref)};

    CHECK(result == result_type{result_variant{fcppt::make_ref(d1)}});
  }

  {
    derived3 d3{};

    base &base_ref{d3};

    result_type const result{
        fcppt::variant::dynamic_cast_<derived_types, fcppt::cast::dynamic_fun>(base_ref)};

    CHECK(result == result_type{});
  }
}

TEST_CASE("variant::dynamic_cast const", "[variant]")
{
  using derived_types = metal::list<derived1 const, derived2 const>;

  using result_variant =
      fcppt::variant::from_list<fcppt::variant::dynamic_cast_types<derived_types>>;

  using result_type = fcppt::optional::object<result_variant>;

  derived2 d2{};

  base const &base_ref{d2};

  {
    result_type const result{
        fcppt::variant::dynamic_cast_<derived_types, fcppt::cast::dynamic_fun>(base_ref)};

    CHECK(result == result_type{result_variant{fcppt::make_cref(d2)}});
  }
}

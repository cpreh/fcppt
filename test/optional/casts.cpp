//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/const_cast.hpp>
#include <fcppt/optional/dynamic_cast.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/optional/static_cast.hpp>
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
  derived() = default;

  ~derived() override = default;
};

using optional_base_ref = fcppt::optional::reference<base>;

using optional_derived_ref = fcppt::optional::reference<derived>;

}

TEST_CASE("optional::dynamic_cast", "[optional]")
{
  optional_base_ref const empty_base{};

  CHECK(fcppt::optional::dynamic_cast_<derived>(empty_base) == optional_derived_ref{});

  derived derived_object{};

  optional_base_ref const base_ref{fcppt::reference<base>(derived_object)};

  optional_derived_ref const derived_ref(fcppt::optional::dynamic_cast_<derived>(base_ref));

  CHECK(derived_ref == optional_derived_ref{fcppt::make_ref(derived_object)});
}

TEST_CASE("optional::static_cast", "[optional]")
{
  optional_base_ref const empty_base{};

  CHECK(fcppt::optional::static_cast_<derived>(empty_base) == optional_derived_ref{});

  derived derived_object{};

  optional_base_ref const base_ref{fcppt::reference<base>(derived_object)};

  optional_derived_ref const derived_ref(fcppt::optional::static_cast_<derived>(base_ref));

  CHECK(derived_ref == optional_derived_ref(fcppt::make_ref(derived_object)));
}

TEST_CASE("optional::const_cast"
          "[optional]")
{
  using optional_const_base_ref = fcppt::optional::reference<base const>;

  base object{};

  optional_const_base_ref const ref(fcppt::make_cref(object));

  optional_base_ref const nonconst_ref(fcppt::optional::const_cast_<base>(ref));

  CHECK(nonconst_ref == optional_base_ref(fcppt::make_ref(object)));
}

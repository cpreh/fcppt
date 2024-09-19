//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

namespace
{
using int_unique_ptr = fcppt::unique_ptr<int>;

using string_unique_ptr = fcppt::unique_ptr<std::string>;

using bool_unique_ptr = fcppt::unique_ptr<bool>;

struct function
{
  template <typename T1, typename T2, typename T3>
  void operator()(T1 &, T2 &, T3 &) const
  {
    CHECK(false);
  }

  void operator()(
      int_unique_ptr &_int, // NOLINT(google-runtime-references)
      string_unique_ptr &_string, // NOLINT(google-runtime-references)
      bool_unique_ptr &_bool // NOLINT(google-runtime-references)
  ) const
  {
    CHECK(*_int == 1);

    CHECK(*_string == "test");

    CHECK(*_bool);
  }
};

using move_result = fcppt::tuple::object<int_unique_ptr, string_unique_ptr, bool_unique_ptr>;

struct move_function
{
  template <typename T1, typename T2, typename T3>
  // NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
  move_result operator()(T1 &&, T2 &&, T3 &&) const
  {
    throw std::runtime_error{"impossible"};
  }

  move_result
  operator()(int_unique_ptr &&_int, string_unique_ptr &&_string, bool_unique_ptr &&_bool) const
  {
    return move_result{std::move(_int), std::move(_string), std::move(_bool)};
  }
};

using variant = fcppt::variant::object<int_unique_ptr, string_unique_ptr, bool_unique_ptr>;

}

TEST_CASE("variant::apply ref", "[variant]")
{
  variant int_variant(fcppt::make_unique_ptr<int>(1));

  variant string_variant(fcppt::make_unique_ptr<std::string>(std::string{"test"}));

  variant bool_variant(fcppt::make_unique_ptr<bool>(true));

  function const func{};

  fcppt::variant::apply(func, int_variant, string_variant, bool_variant);
}

TEST_CASE("variant_apply move", "[variant]")
{
  move_result const result{fcppt::variant::apply(
      move_function{},
      variant{fcppt::make_unique_ptr<int>(1)},
      variant{fcppt::make_unique_ptr<std::string>(std::string{"test"})},
      variant{fcppt::make_unique_ptr<bool>(true)})};

  CHECK(*fcppt::tuple::get<0>(result) == 1);

  CHECK(*fcppt::tuple::get<1>(result) == "test");

  CHECK(*fcppt::tuple::get<2>(result));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
using variant = fcppt::variant::object<bool, int, std::string>;

}

TEST_CASE("variany::apply_unary nonconst", "[variant]")
{
  variant v1(std::string("foo"));

  fcppt::variant::apply(
      [](auto &_val) { _val = fcppt::type_traits::remove_cv_ref_t<decltype(_val)>{}; }, v1);

  CHECK(fcppt::variant::get_unsafe<std::string>(v1).empty());
}

TEST_CASE("variany::apply_binary nonconst", "[variant]")
{
  variant v1(std::string("foo"));

  variant v2(1);

  fcppt::variant::apply(
      [](auto &_val1, auto &_val2) {
        _val1 = fcppt::type_traits::remove_cv_ref_t<decltype(_val1)>{};

        _val2 = fcppt::type_traits::remove_cv_ref_t<decltype(_val2)>{};
      },
      v1,
      v2);

  CHECK(fcppt::variant::get_unsafe<std::string>(v1).empty());

  CHECK(fcppt::variant::get_unsafe<int>(v2) == 0);
}

TEST_CASE("variany::apply_ternary nonconst", "[variant]")
{
  variant v1(std::string("foo"));

  variant v2(1);

  variant v3(true);

  fcppt::variant::apply(
      [](auto &_val1, auto &_val2, auto &_val3) {
        _val1 = fcppt::type_traits::remove_cv_ref_t<decltype(_val1)>{};

        _val2 = fcppt::type_traits::remove_cv_ref_t<decltype(_val2)>{};

        _val3 = fcppt::type_traits::remove_cv_ref_t<decltype(_val3)>{};
      },
      v1,
      v2,
      v3);

  CHECK(fcppt::variant::get_unsafe<std::string>(v1).empty());

  CHECK(fcppt::variant::get_unsafe<int>(v2) == 0);

  CHECK_FALSE(fcppt::variant::get_unsafe<bool>(v3));
}

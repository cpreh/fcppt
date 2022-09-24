//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("variant assign", "[variant]")
{
  using variant = fcppt::variant::object<int, std::string>;

  variant test1(0);

  variant const test2(std::string("test"));

  test1 = test2;

  CHECK(fcppt::variant::holds_type<std::string>(test1));

  CHECK(fcppt::variant::get_unsafe<std::string>(test1) == std::string("test"));

  test1 = variant{1};

  CHECK(fcppt::variant::holds_type<int>(test1));

  CHECK(fcppt::variant::get_unsafe<int>(test1) == 1);
}

FCPPT_CATCH_END

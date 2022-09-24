//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("variant::holds_type", "[variant]")
{
  using variant = fcppt::variant::object<int, std::string>;

  std::string const string("hello world");

  variant const test(string);

  CHECK(fcppt::variant::holds_type<std::string>(test));

  CHECK_FALSE(fcppt::variant::holds_type<int>(test));

  variant const test2(42);

  CHECK_FALSE(fcppt::variant::holds_type<std::string>(test2));

  CHECK(fcppt::variant::holds_type<int>(test2));
}

FCPPT_CATCH_END

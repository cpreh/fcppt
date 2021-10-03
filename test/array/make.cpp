//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/make.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("array::make", "[array]")
{
  std::string const string_ref{"100"};

  CHECK(
      fcppt::array::make(std::string{"42"}, string_ref) ==
      fcppt::array::object<std::string, 2>{std::string{"42"}, std::string{"100"}});
}

FCPPT_CATCH_END

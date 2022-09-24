//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/get_or_assign.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::get_or_assign", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  optional_int test{};

  int const &result1{fcppt::optional::get_or_assign(test, fcppt::const_(1))};

  CHECK(result1 == 1);

  int const &result2{fcppt::optional::get_or_assign(test, fcppt::const_(2))};

  CHECK(result2 == 1);
}

FCPPT_CATCH_END

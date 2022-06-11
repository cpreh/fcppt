//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/tuple.hpp>
#include <fcppt/tuple/apply.hpp>
#include <fcppt/tuple/comparison.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("tuple::apply", "[tuple]")
{
  CHECK(
      fcppt::tuple::apply(
          [](auto &&..._args) { return fcppt::tuple::make(std::forward<decltype(_args)>(_args)...); },
          fcppt::tuple::make(1, true, std::string{"test"}),
          fcppt::tuple::make(false, std::string{"x"}, false)) ==
      fcppt::tuple::make(
          fcppt::tuple::make(1, false),
          fcppt::tuple::make(true, std::string{"x"}),
          fcppt::tuple::make(std::string{"test"}, false)));
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/tuple/invoke.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("tuple::invoke", "[tuple]")
{
  struct F{
    bool
	operator()(int const i, std::string const &s) const
	{
	  return i == 10 && s == "test";
	}
  };
  CHECK(fcppt::tuple::invoke(F{},fcppt::tuple::make(10,std::string{"test"})));
}

FCPPT_CATCH_END

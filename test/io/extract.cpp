//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/extract.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::extract", "[io]")
{
  {
    std::istringstream stream{"xy"};

    CHECK(fcppt::io::extract<int>(stream) == fcppt::optional::object<int>{});
  }

  {
    std::istringstream stream{"42"};

    CHECK(fcppt::io::extract<int>(stream) == fcppt::optional::make(42));
  }
}

FCPPT_CATCH_END

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/get.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::get", "[io]")
{
  std::istringstream stream{"x"};

  using optional_char = fcppt::optional::object<char>;

  CHECK(fcppt::io::get(stream) == optional_char{'x'});

  CHECK(fcppt::io::get(stream) == optional_char{});
}

FCPPT_CATCH_END

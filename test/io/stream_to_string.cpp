//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/stream_to_string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::stream_to_string", "[io]")
{
  {
    // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
    std::istringstream istream{"TEST abcd"};

    CHECK(fcppt::io::stream_to_string(istream) == fcppt::optional::make(std::string{"TEST abcd"}));
  }

  {
    // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
    std::istringstream istream{};

    CHECK(fcppt::io::stream_to_string(istream) == fcppt::optional::make(std::string{}));
  }
}

FCPPT_CATCH_END

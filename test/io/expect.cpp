//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/io/expect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

TEST_CASE("io::expect", "[io]")
{
  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  std::istringstream stream{"xy"};

  fcppt::io::expect(stream, 'x');

  CHECK(stream);

  fcppt::io::expect(stream, 'x');

  CHECK_FALSE(stream);
}

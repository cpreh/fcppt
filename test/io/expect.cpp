//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/expect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::expect", "[io]")
{
  std::istringstream stream{"xy"};

  fcppt::io::expect(stream, 'x');

  CHECK(stream);

  fcppt::io::expect(stream, 'x');

  CHECK_FALSE(stream);
}

FCPPT_CATCH_END

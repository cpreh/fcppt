//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("io::widen_string", "[io]")
{
  fcppt::io::ostringstream stream{};

  stream << fcppt::io::widen_string("test");

  CHECK(stream.str() == FCPPT_TEXT("test"));
}

FCPPT_CATCH_END

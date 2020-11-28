//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("variant output", "[variant]")
{
  using variant = fcppt::variant::object<int>;

  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  fcppt::io::ostringstream stream{};

  stream << variant{1};

  CHECK(stream.str() == fcppt::string{FCPPT_TEXT("1")});
}

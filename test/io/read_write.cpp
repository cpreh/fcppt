//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/endianness/format.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/io/write.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>

namespace
{
using optional_int = fcppt::optional::object<int>;

void test_read_write(fcppt::endianness::format const _endianness)
{
  int const foo{42};

  // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
  std::stringstream stream{};

  fcppt::io::write(stream, foo, _endianness);

  optional_int const result(fcppt::io::read<int>(stream, _endianness));

  CHECK(result == optional_int{42});
}

}

TEST_CASE("io read_write", "[io]")
{
  test_read_write(fcppt::endianness::format::big);

  test_read_write(fcppt::endianness::format::little);

  {
    // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
    std::stringstream stream{};

    CHECK(fcppt::io::read<int>(stream, fcppt::endianness::format::little) == optional_int{});
  }
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/endianness/convert.hpp>
#include <fcppt/endianness/swap.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <bit>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("endianness", "[endianness]")
{
  int const foo{108};

  CHECK(
      ((std::endian::native == std::endian::little &&
        fcppt::endianness::convert(foo, std::endian::little) == 108) ||
       (std::endian::native == std::endian::big &&
        fcppt::endianness::convert(foo, std::endian::big) == 108)));

  CHECK(fcppt::endianness::swap(fcppt::endianness::swap(foo)) == foo);

  CHECK(
      fcppt::endianness::convert(
          fcppt::endianness::convert(foo, std::endian::big),
          std::endian::big) == 108);

  CHECK(
      fcppt::endianness::convert(
          fcppt::endianness::convert(foo, std::endian::little),
          std::endian::little) == 108);
}

FCPPT_CATCH_END

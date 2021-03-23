//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::bitfield empty", "[container],[bitfield]")
{
  using static_size = std::integral_constant<unsigned, 0>;

  using empty_bitfield = fcppt::container::bitfield::object<unsigned, static_size>;

  CHECK(empty_bitfield{fcppt::no_init()}.array().impl().empty());

  static_assert(empty_bitfield::static_size::value == 0U);
}

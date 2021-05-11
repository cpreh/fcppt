//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/metal/invoke_on.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <catch2/catch.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

TEST_CASE("metal::invoke_on", "[metal]")
{
  using list_type = metal::list<
      int,
      long // NOLINT(google-runtime-int)
      >;

  CHECK(fcppt::metal::invoke_on<list_type>(
      1U,
      []<typename Type>(fcppt::tag<Type>) -> bool {
        return std::is_same_v<Type, long>;
      },
      fcppt::const_(false)));

  CHECK(fcppt::metal::invoke_on<list_type>(
      0U,
      []<typename Type>(fcppt::tag<Type>) -> bool {
        return std::is_same_v<Type, int>;
      },
      fcppt::const_(false)));

  CHECK(fcppt::metal::invoke_on<list_type>(
      2U, [](auto) -> bool { return false; }, fcppt::const_(true)));
}

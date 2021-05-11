//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
using int_type = unsigned;

template <int_type Value>
using int_c = std::integral_constant<int_type, Value>;

}

TEST_CASE("runtime_index", "[various]")
{
  using max_index = int_c<2U>;

  CHECK(fcppt::runtime_index<max_index>(
      0U,
      []<int_type Index>(int_c<Index>) -> bool {
        return Index == 0U;
      },
      fcppt::const_(false)));

  CHECK(fcppt::runtime_index<max_index>(
      1U,
      []<int_type Index>(int_c<Index>) -> bool {
        return Index == 1U;
      },
      fcppt::const_(false)));

  CHECK(fcppt::runtime_index<max_index>(
      2U, [](auto) -> bool { return false; }, fcppt::const_(true)));
}

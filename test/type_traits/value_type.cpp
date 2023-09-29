//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
  using vector = std::vector<int>;

  using array = std::array<bool, 2>;

  static_assert(std::is_same_v<fcppt::type_traits::value_type<vector>, int>, "value_type not int");

  static_assert(std::is_same_v<fcppt::type_traits::value_type<array>, bool>, "value_type not bool");
}

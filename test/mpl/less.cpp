//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/less.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  static_assert(fcppt::mpl::less<std::integral_constant<int, 2>, std::integral_constant<int, 3>>::value);
  static_assert(!fcppt::mpl::less<std::integral_constant<int, 5>, std::integral_constant<int, 3>>::value);
}

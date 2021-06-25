//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using interval = fcppt::mpl::list::interval<int, 3, 5>;

  static_assert(std::is_same_v<
                interval,
                fcppt::mpl::list::
                    object<std::integral_constant<int, 3>, std::integral_constant<int, 4>>>);
}

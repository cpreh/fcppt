//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/is_set.hpp>
#include <fcppt/mpl/list/object.hpp>

int main()
{
  static_assert(fcppt::mpl::list::is_set<fcppt::mpl::list::object<int, float>>::value);

  static_assert(!fcppt::mpl::list::is_set<fcppt::mpl::list::object<int, int>>::value);
}

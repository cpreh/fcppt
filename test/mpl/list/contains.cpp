//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/contains.hpp>
#include <fcppt/mpl/list/object.hpp>

int main()
{
  static_assert(!fcppt::mpl::list::contains<fcppt::mpl::list::object<>, int>::value);

  static_assert(fcppt::mpl::list::contains<fcppt::mpl::list::object<int, bool>, int>::value);

  static_assert(!fcppt::mpl::list::contains<fcppt::mpl::list::object<bool>, int>::value);
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/set/contains_v.hpp>
#include <fcppt/mpl/set/from_list_relaxed.hpp>

int main()
{
  using set = fcppt::mpl::set::from_list_relaxed<fcppt::mpl::list::object<bool,int,int>>;

  static_assert(fcppt::mpl::set::contains_v<set,bool>);
  static_assert(fcppt::mpl::set::contains_v<set,int>);
}

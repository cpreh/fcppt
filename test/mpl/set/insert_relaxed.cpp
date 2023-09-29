//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/set/contains_v.hpp>
#include <fcppt/mpl/set/insert_relaxed.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  using set = fcppt::mpl::set::object<char,int>;

  static_assert(std::is_same_v<fcppt::mpl::set::insert_relaxed<set, char>, set>);

  static_assert(fcppt::mpl::set::contains_v<fcppt::mpl::set::insert_relaxed<set, bool>, bool>);
}

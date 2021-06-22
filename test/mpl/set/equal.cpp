//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/set/equal.hpp>
#include <fcppt/mpl/set/object.hpp>

int main()
{
  static_assert(
      fcppt::mpl::set::equal<fcppt::mpl::set::object<>, fcppt::mpl::set::object<>>::value);
  static_assert(
      fcppt::mpl::set::equal<fcppt::mpl::set::object<int>, fcppt::mpl::set::object<int>>::value);
  static_assert(
      fcppt::mpl::set::
          equal<fcppt::mpl::set::object<int, bool>, fcppt::mpl::set::object<bool, int>>::value);
  static_assert(
      !fcppt::mpl::set::
          equal<fcppt::mpl::set::object<int, float>, fcppt::mpl::set::object<bool, int>>::value);
}

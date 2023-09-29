//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/distinct_v.hpp>
#include <fcppt/mpl/list/object.hpp>

int main()
{
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::list::distinct<fcppt::mpl::list::object<>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::list::distinct<fcppt::mpl::list::object<int>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::list::distinct<fcppt::mpl::list::object<int,float>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::mpl::list::distinct<fcppt::mpl::list::object<int,int>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::mpl::list::distinct<fcppt::mpl::list::object<int,int,float>>::value);
  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::mpl::list::distinct<fcppt::mpl::list::object<int,float,bool>>::value);

  static_assert(fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<>>);
  static_assert(fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<int>>);
  static_assert(fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<int,float>>);
  static_assert(!fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<int,int>>);
  static_assert(!fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<int,int,float>>);
  static_assert(fcppt::mpl::list::distinct_v<fcppt::mpl::list::object<int,float,bool>>);
}

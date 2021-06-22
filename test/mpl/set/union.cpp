//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/union.hpp>

int main()
{
  using result =
      fcppt::mpl::set::union_<fcppt::mpl::set::object<bool, int>, fcppt::mpl::set::object<int, float>>;

  static_assert(fcppt::mpl::set::contains<result, int>::value);

  static_assert(fcppt::mpl::set::contains<result, bool>::value);

  static_assert(fcppt::mpl::set::contains<result, float>::value);
}

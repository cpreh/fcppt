//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/difference.hpp>
#include <fcppt/mpl/set/object.hpp>

int main()
{
  using result = fcppt::mpl::set::
      difference<fcppt::mpl::set::object<bool, int>, fcppt::mpl::set::object<int, float>>;

  static_assert(fcppt::not_(fcppt::mpl::set::contains<result, int>::value));

  static_assert(fcppt::mpl::set::contains<result, bool>::value);

  static_assert(fcppt::not_(fcppt::mpl::set::contains<result, float>::value));
}

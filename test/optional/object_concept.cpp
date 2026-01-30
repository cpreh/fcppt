//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/object_fwd.hpp>

int main()
{
  static_assert(fcppt::optional::object_concept<fcppt::optional::object<int>>);
  static_assert(fcppt::optional::object_concept<fcppt::optional::object<int> &>);
  static_assert(fcppt::optional::object_concept<fcppt::optional::object<int> const &>);
  static_assert(fcppt::optional::object_concept<fcppt::optional::object<int> &&>);
  static_assert(fcppt::not_(fcppt::optional::object_concept<int>));
}

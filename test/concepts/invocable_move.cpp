//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/function_impl.hpp>
#include <fcppt/not.hpp>
#include <fcppt/concepts/invocable_move.hpp>


int main()
{
  static_assert(fcppt::concepts::invocable_move<fcppt::function<int (int)>, int>);
  static_assert(fcppt::not_(fcppt::concepts::invocable_move<fcppt::function<void (int)>, int>));
  static_assert(fcppt::not_(fcppt::concepts::invocable_move<fcppt::function<void (int, int)>, int>));
  static_assert(fcppt::not_(fcppt::concepts::invocable_move<int, int>));
}

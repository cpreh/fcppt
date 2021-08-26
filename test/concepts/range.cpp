//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/not.hpp>
#include <fcppt/concepts/range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


int main()
{
  static_assert(fcppt::concepts::range<std::vector<int>>);
  static_assert(fcppt::not_(fcppt::concepts::range<int>));
}

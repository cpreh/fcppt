//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/is_reference.hpp>
#include <fcppt/reference_fwd.hpp>

int main()
{
  static_assert(fcppt::is_reference<fcppt::reference<int>>::value);

  static_assert(!fcppt::is_reference<int>::value);
}

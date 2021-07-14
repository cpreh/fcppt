//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  // prints (int, float, double) to cout
  std::cout << fcppt::mpl::list::object<int, float, double>{} << '\n';
  //! [mpl_print}
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  {
    //[mathpowerof2
    unsigned const i = 1024;

    std::cout << std::boolalpha << fcppt::math::is_power_of_2(i) << '\n';

    //]
  }
}

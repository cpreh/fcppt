//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/get.hpp>
#include <fcppt/array/map.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  //! [array_map]
  using three_ints = fcppt::array::object<int, 3>;

  three_ints const a{1, 2, 3};

  three_ints const b(fcppt::array::map(a, [](int const _arg) { return _arg * 3; }));

  // b now contains: 3, 6, 9
  //! [array_map]
  std::cout << fcppt::array::get<0U>(b) << '\n';
}

//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <vector>
#include <fcppt/config/external_end.hpp>

int main()
{
  // ![assign]
  using int_unique_ptr_vector = std::vector<fcppt::unique_ptr<int>>;

  auto const int_ptrs(fcppt::container::make<int_unique_ptr_vector>(
      fcppt::make_unique_ptr<int>(1), fcppt::make_unique_ptr<int>(2)));

  // Prints 1 2
  for (auto const &elem : int_ptrs)
  {
    std::cout << *elem << '\n';
  }
  // ![assign]
}

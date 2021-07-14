//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/container/grid/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

//! [grid_iteration]
namespace
{
using int1d_grid = fcppt::container::grid::object<int, 1>;

using int2d_grid = fcppt::container::grid::object<int, 2>;

}

int main()
{
  int1d_grid one_dimensional(int1d_grid::dim(3U), 0);

  one_dimensional.get_unsafe(int1d_grid::pos(0U)) = 0;
  one_dimensional.get_unsafe(int1d_grid::pos(1U)) = 1;
  one_dimensional.get_unsafe(int1d_grid::pos(2U)) = 2;

  // Outputs 0, 1, 2
  for (auto const &elem : one_dimensional)
  {
    std::cout << elem << ' ';
  }

  std::cout << '\n';

  int2d_grid two_dimensional(int2d_grid::dim(3U, 2U), 0);

  two_dimensional.get_unsafe(int2d_grid::pos(0U, 0U)) = 0;
  two_dimensional.get_unsafe(int2d_grid::pos(1U, 0U)) = 1;
  two_dimensional.get_unsafe(int2d_grid::pos(2U, 0U)) = 2;
  two_dimensional.get_unsafe(int2d_grid::pos(0U, 1U)) = 3;
  two_dimensional.get_unsafe(int2d_grid::pos(1U, 1U)) = 4;
  two_dimensional.get_unsafe(int2d_grid::pos(2U, 1U)) = 5;

  // Outputs 0, 1, 2, 3, 4, 5
  for (auto const &elem : two_dimensional)
  {
    std::cout << elem << ' ';
  }

  std::cout << '\n';
}
//! [grid_iteration]

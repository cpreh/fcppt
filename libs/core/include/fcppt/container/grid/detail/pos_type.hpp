//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_TYPE_HPP_INCLUDED

#include <fcppt/container/grid/is_object.hpp>

namespace fcppt::container::grid::detail
{
template <typename Grid>
struct pos_type
{
  static_assert(fcppt::container::grid::is_object<Grid>::value, "Grid must be a grid");

  using type = typename Grid::pos;
};

}

#endif

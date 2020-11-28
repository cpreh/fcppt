//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_REF_CRANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_REF_CRANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_ref_range.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
/**
\brief A const pos ref range over a grid

\ingroup fcpptcontainergrid
*/
template <typename Grid>
inline fcppt::container::grid::pos_ref_range<Grid const> make_pos_ref_crange(Grid const &_grid)
{
  return fcppt::container::grid::make_pos_ref_range(_grid);
}

}
}
}

#endif

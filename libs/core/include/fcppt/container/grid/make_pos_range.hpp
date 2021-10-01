//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/math/dim/to_vector.hpp>
#include <fcppt/math/vector/null.hpp>

namespace fcppt::container::grid
{
/**
\brief A range over all positions

\ingroup fcpptcontainergrid

Creates a range of positions from "all zeroes" to, but not including, \a _size.
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
inline fcppt::container::grid::pos_range<SizeType, Size>
make_pos_range(fcppt::container::grid::dim<SizeType, Size> const _size)
{
  return fcppt::container::grid::make_pos_range_start_end(
      fcppt::container::grid::min<SizeType, Size>(
          fcppt::math::vector::null<fcppt::container::grid::pos<SizeType, Size>>()),
      fcppt::container::grid::sup<SizeType, Size>(fcppt::math::dim::to_vector(_size)));
}

}

#endif

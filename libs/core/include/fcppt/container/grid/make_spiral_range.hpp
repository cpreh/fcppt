//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_MAKE_SPIRAL_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_SPIRAL_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/spiral_range_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::container::grid
{
template <typename Pos>
inline fcppt::container::grid::spiral_range<Pos>
make_spiral_range(Pos const _start, fcppt::type_traits::value_type<Pos> const _max_dist)
{
  return fcppt::container::grid::spiral_range<Pos>(_start, _max_dist);
}

}

#endif

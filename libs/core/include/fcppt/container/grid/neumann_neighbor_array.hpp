//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_NEUMANN_NEIGHBOR_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_NEUMANN_NEIGHBOR_ARRAY_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>

namespace fcppt::container::grid
{
/**
\ingroup fcpptcontainergrid

\brief The type return by fcppt::container::grid::neumann_neighbors

\tparam Pos Must be an fcppt::container::grid::pos
*/
template <typename Pos>
using neumann_neighbor_array = fcppt::array::object<Pos, 4>;

}

#endif

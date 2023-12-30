//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_MOORE_NEIGHBOR_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MOORE_NEIGHBOR_ARRAY_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>

namespace fcppt::container::grid
{
/**
\ingroup fcpptcontainergrid

\brief The type return by fcppt::container::grid::moore_neighbors

\tparam Pos Must be an fcppt::container::grid::pos
*/
template <typename Pos>
using moore_neighbor_array = fcppt::array::object<
    Pos,
    8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    >;

}

#endif

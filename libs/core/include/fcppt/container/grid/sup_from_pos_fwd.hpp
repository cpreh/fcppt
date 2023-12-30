//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_SUP_FROM_POS_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SUP_FROM_POS_FWD_HPP_INCLUDED

#include <fcppt/container/grid/pos.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/sup_fwd.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::container::grid
{
/**
\brief Creates the sup from a pos type

\ingroup fcpptcontainergrid
*/
template <typename Pos>
using sup_from_pos =
    fcppt::container::grid::sup<fcppt::type_traits::value_type<Pos>, Pos::static_size::value>;

}

#endif

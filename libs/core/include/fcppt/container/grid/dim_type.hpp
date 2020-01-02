//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DIM_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DIM_TYPE_HPP_INCLUDED

#include <fcppt/container/grid/detail/dim_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief The dim type of a grid.

\ingroup fcpptcontainergrid

\tparam Grid Must be an #fcppt::container::grid::object.
*/
template<
	typename Grid
>
using
dim_type
=
typename
fcppt::container::grid::detail::dim_type<
	Grid
>::type;

}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_REF_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/dim/to_vector.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A pos ref range over a grid

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
inline
fcppt::container::grid::pos_ref_range<
	Grid
> const
make_pos_ref_range(
	Grid &_grid
)
{
	return
		fcppt::container::grid::make_pos_ref_range_start_end(
			_grid,
			fcppt::container::grid::min_from_pos<
				typename
				Grid::pos
			>(
				Grid::pos::null()
			),
			fcppt::container::grid::sup_from_pos<
				typename
				Grid::pos
			>(
				fcppt::math::dim::to_vector(
					_grid.size()
				)
			)
		);
}

}
}
}

#endif

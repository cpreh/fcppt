#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
fcppt::container::grid::pos_range<
	Grid
> const
make_pos_range(
	Grid &_grid
)
{
	return
		fcppt::container::grid::make_pos_range_start_end(
			_grid,
			Grid::dim::null(),
			_grid.size()
		);
}

}
}
}

#endif

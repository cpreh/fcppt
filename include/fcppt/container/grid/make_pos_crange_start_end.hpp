#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_START_END_HPP_INCLUDED

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
	Grid const
> const
make_pos_crange_start_end(
	Grid const &_grid,
	typename Grid::dim const &_start,
	typename Grid::dim const &_end
)
{
	return
		fcppt::container::grid::make_pos_range_start_end(
			_grid,
			_start,
			_end
		);
}

}
}
}

#endif

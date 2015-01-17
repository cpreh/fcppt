//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/pos_range_impl.hpp>
#include <fcppt/math/dim/to_vector.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename Grid
>
inline
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
			Grid::pos::null(),
			fcppt::math::dim::to_vector(
				_grid.size()
			)
		);
}

}
}
}

#endif

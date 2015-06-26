//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_START_END_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_START_END_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_range_start_end.hpp>
#include <fcppt/container/grid/pos_ref_range_impl.hpp>


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
fcppt::container::grid::pos_ref_range<
	Grid const
> const
make_pos_crange_start_end(
	Grid const &_grid,
	typename Grid::pos const &_start,
	typename Grid::pos const &_end
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

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_SAME_SIZES_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_SAME_SIZES_HPP_INCLUDED

#include <fcppt/math/dim/comparison.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

// TODO: Express this using algorithms and ranges
template<
	typename Grid
>
inline
bool
same_sizes(
	Grid const &
)
{
	return
		true;
}

template<
	typename Grid1,
	typename Grid2,
	typename... Grids
>
inline
bool
same_sizes(
	Grid1 const &_grid1,
	Grid2 const &_grid2,
	Grids const &... _grids
)
{
	return
		_grid1.size()
		==
		_grid2.size()
		&&
		fcppt::container::grid::detail::same_sizes(
			_grid2,
			_grids...
		);
}

}
}
}
}

#endif

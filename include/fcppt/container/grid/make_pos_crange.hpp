//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_POS_CRANGE_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_range.hpp>
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
make_pos_crange(
	Grid const &_grid
)
{
	return
		fcppt::container::grid::make_pos_range(
			_grid
		);
}

}
}
}

#endif

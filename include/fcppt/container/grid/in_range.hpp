//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IN_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IN_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
in_range(
	grid::object<T, N, A> const &_grid,
	typename grid::object<T, N, A>::dim const &_pos
)
{
	for(
		grid::size_type index(
			0u
		);
		index < N;
		++index
	)
		if(
			_pos[
				index
			]
			>=
			_grid.size()[
				index
			]
		)
			return false;

	return true;
}

}
}
}

#endif

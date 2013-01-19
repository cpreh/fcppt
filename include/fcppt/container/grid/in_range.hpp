//          Copyright Carl Philipp Reh 2009 - 2013.
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

/**
 * \brief Checks if the given position \p _pos is out of bounds.
 * \returns <code>true</code> if is not out of bounds, <code>false</code> otherwise.
 * \ingroup fcpptcontainergrid
 */
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
bool
in_range(
	fcppt::container::grid::object<T, N, A> const &_grid,
	typename fcppt::container::grid::object<T, N, A>::dim const &_pos
)
{
	for(
		fcppt::container::grid::size_type index(
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

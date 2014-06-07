//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IN_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IN_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/in_range_dim.hpp>
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
inline
bool
in_range(
	fcppt::container::grid::object<T, N, A> const &_grid,
	typename fcppt::container::grid::object<T, N, A>::pos const &_pos
)
{
	return
		fcppt::container::grid::in_range_dim(
			_grid.size(),
			_pos
		);
}

}
}
}

#endif

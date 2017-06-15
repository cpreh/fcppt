//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MOORE_NEIGHBORS_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MOORE_NEIGHBORS_HPP_INCLUDED

#include <fcppt/container/grid/moore_neighbor_array.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\ingroup fcpptcontainergrid

\brief Computes the Moore neighbors

Computes the Moore neighbors of \a _pos. No range checking is performed.

\param _pos The position to compute the neighbors of

\return An array with four elements, containing the neighbors
*/
template<
	typename T,
	fcppt::container::grid::size_type N
>
fcppt::container::grid::moore_neighbor_array<
	fcppt::container::grid::pos<
		T,
		N
	>
>
moore_neighbors(
	fcppt::container::grid::pos<
		T,
		N
	> const _pos
)
{
	typedef
	fcppt::container::grid::pos<
		T,
		N
	>
	pos_type;

	return
		fcppt::container::grid::moore_neighbor_array<
			pos_type
		>{{
			pos_type{
				_pos.x() - 1,
				_pos.y()
			},
			pos_type{
				_pos.x() + 1,
				_pos.y()
			},
			pos_type{
				_pos.x(),
				_pos.y() - 1,
			},
			pos_type{
				_pos.x(),
				_pos.y() + 1
			},
			pos_type{
				_pos.x() - 1,
				_pos.y() - 1
			},
			pos_type{
				_pos.x() - 1,
				_pos.y() + 1
			},
			pos_type{
				_pos.x() + 1,
				_pos.y() - 1
			},
			pos_type{
				_pos.x() + 1,
				_pos.y() + 1
			}
		}};
}

}
}
}

#endif

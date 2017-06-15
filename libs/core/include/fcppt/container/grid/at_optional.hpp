//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_AT_OPTIONAL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_AT_OPTIONAL_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/container/grid/in_range.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns a grid element as an optional

\ingroup fcpptcontainergrid

If \a _pos is in the range of \a _grid, the element at \a _pos is returned.
Otherwise, the result is an empty optional.
*/
template<
	typename Grid
>
fcppt::optional::reference<
	fcppt::container::to_value_type<
		Grid
	>
>
at_optional(
	Grid &_grid,
	typename Grid::pos const _pos
)
{
	typedef
	fcppt::optional::reference<
		fcppt::container::to_value_type<
			Grid
		>
	>
	result_type;

	return
		fcppt::container::grid::in_range(
			_grid,
			_pos
		)
		?
			result_type{
				fcppt::make_ref(
					_grid[
						_pos
					]
				)
			}
		:
			result_type{}
		;
}

}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IS_SQUARE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IS_SQUARE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/at_c.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\ingroup fcpptcontainergrid
\brief Checks if a grid is a square or a rectangle
\returns <code>true</code> of the grid is square, <code>false</code> otherwise
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
bool
is_square(
	fcppt::container::grid::dim<
		SizeType,
		Size
	> const &_size
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::make_int_range(
				fcppt::literal<
					fcppt::container::grid::size_type
				>(
					1
				),
				Size
			),
			[
				&_size
			](
				fcppt::container::grid::size_type const _index
			)
			{
				return
					fcppt::math::at_c<
						0
					>(
						_size
					)
					==
					_size[
						_index
					];
			}
		);
}

}
}
}

#endif

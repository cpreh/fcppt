//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_FILL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_FILL_HPP_INCLUDED

#include <fcppt/container/grid/make_pos_ref_range.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Fills a grid using a function

\ingroup fcpptcontainergrid

\tparam Function A function callable as <code>T (dim<size_type, N>)</code>.
*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Function
>
void
fill(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_grid,
	Function const &_function
)
{
	for(
		auto const &element
		:
		fcppt::container::grid::make_pos_ref_range(
			_grid
		)
	)
		element.value() =
			_function(
				element.pos()
			);
}

}
}
}

#endif

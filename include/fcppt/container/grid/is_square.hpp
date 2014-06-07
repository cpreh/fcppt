//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IS_SQUARE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IS_SQUARE_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>

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
template<typename T,grid::size_type N>
bool
is_square(
	grid::object<T,N> const &g)
{
	for(typename grid::object<T,N>::dim::size_type i = 1; i < g.size().size(); ++i)
		if(g.size()[i] != g.size()[0])
			return false;
	return true;
}
}
}
}

#endif

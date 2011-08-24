//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_ITERATOR_POSITION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_ITERATOR_POSITION_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <iterator>

namespace fcppt
{
namespace container
{
namespace grid
{
template<typename Grid,typename Iterator>
typename Grid::dim const
iterator_position(
	Grid const &grid,
	Iterator const it)
{
	typedef typename
	Grid::dim
	dim;

	typedef typename
	dim::value_type
	dim_unit;

	typedef typename
	dim::size_type
	dim_size_type;

	dim stacked_dim;
	stacked_dim[0] = grid.size()[0];

	for(dim_size_type i = 1; i < stacked_dim.size(); ++i)
		stacked_dim[i] =
			stacked_dim[static_cast<dim_size_type>(i-1)] * grid.size()[i];

	dim ret;

	dim_unit const offset =
		static_cast<dim_unit>(
			std::distance(
				grid.begin(),
				it));

	for(dim_size_type i = 0; i < dim::dim_wrapper::value; ++i)
	{
		ret[i] = offset;

		for(
			dim_size_type m =
				static_cast<dim_size_type>(
					dim::dim_wrapper::value - 1);
			m > i;
			--m)
			ret[i] =
				static_cast<dim_unit>(
					ret[i] % stacked_dim[i]);

		if(i > 0)
			ret[i] =
				static_cast<dim_unit>(
					ret[i] / stacked_dim[i - 1]);
	}

	return
		ret;
}
}
}
}

#endif

//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_AT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_AT_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/container/grid/out_of_range.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Container,
	typename Dim,
	typename Pos
>
fcppt::container::to_reference_type<
	Container
>
at(
	Container &_container,
	Dim const &_dim,
	Pos const &_pos
)
{
	// TODO: Improve this
	for(
		typename Dim::size_type i = 0;
		i < Dim::dim_wrapper::value;
		++i
	)
		if(
			_pos[i]
			>= _dim[i]
		)
			throw fcppt::container::grid::out_of_range();

	return _container[_pos];
}

}
}
}
}

#endif

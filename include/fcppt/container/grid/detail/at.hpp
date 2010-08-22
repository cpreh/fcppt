//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_AT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_AT_HPP_INCLUDED

#include <fcppt/container/grid/detail/choose_reference.hpp>
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
	typename Dim
>
typename detail::choose_reference<
	Container
>::type
at(
	Container &_container,
	Dim const &_dim,
	Dim const &_pos
)
{
	for(
		typename Dim::size_type i = 0;
		i < Dim::dim_wrapper::value;
		++i
	)
		if(
			_pos[i]
			>= _dim[i]
		)
			throw grid::out_of_range();

	return _container[_pos];
}

}
}
}
}

#endif

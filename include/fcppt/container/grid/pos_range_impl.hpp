//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_iterator_impl.hpp>
#include <fcppt/container/grid/pos_range_decl.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_range<
	Grid
>::pos_range(
	Grid &_grid,
	dim const &_start,
	dim const &_end
)
:
	grid_(
		_grid
	),
	start_(
		_start
	),
	end_(
		_end
	)
{
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::begin() const
{
	return
		this->make_iterator(
			start_,
			false
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::end() const
{

	return
		this->make_iterator(
			end_,
			true
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_range<
	Grid
>::iterator
fcppt::container::grid::pos_range<
	Grid
>::make_iterator(
	dim const &_pos,
	bool const _is_end
) const
{
	return
		iterator(
			grid_.begin(),
			grid_.size(),
			_pos,
			start_,
			end_,
			_is_end
		);
}

#endif

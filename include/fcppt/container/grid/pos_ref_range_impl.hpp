//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_ref_range_decl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_impl.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_ref_range<
	Grid
>::pos_ref_range(
	Grid &_grid,
	min const _min,
	sup const _sup
)
:
	grid_(
		_grid
	),
	pos_range_(
		_min,
		_sup
	)
{
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_range<
	Grid
>::iterator
fcppt::container::grid::pos_ref_range<
	Grid
>::begin() const
{
	return
		this->make_iterator(
			pos_range_.begin()
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_range<
	Grid
>::iterator
fcppt::container::grid::pos_ref_range<
	Grid
>::end() const
{
	return
		this->make_iterator(
			pos_range_.end()
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_range<
	Grid
>::size_type
fcppt::container::grid::pos_ref_range<
	Grid
>::size() const
{
	return
		pos_range_.size();
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_range<
	Grid
>::iterator
fcppt::container::grid::pos_ref_range<
	Grid
>::make_iterator(
	pos_iterator const _pos_iterator
) const
{
	return
		iterator(
			grid_.begin(),
			_pos_iterator,
			grid_.size()
		);
}

#endif

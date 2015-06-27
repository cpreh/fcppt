//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/end_position.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_impl.hpp>
#include <fcppt/container/grid/pos_range_decl.hpp>
#include <fcppt/container/grid/size_type.hpp>


template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::pos_range(
	min const _min,
	sup const _sup
)
:
	min_(
		_min
	),
	sup_(
		_sup
	)
{
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
typename
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::iterator
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::begin() const
{
	return
		this->make_iterator(
			min_.get()
		);
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
typename
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::iterator
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::end() const
{
	return
		this->make_iterator(
			fcppt::container::grid::end_position(
				min_,
				sup_
			)
		);
}

template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
typename
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::iterator
fcppt::container::grid::pos_range<
	SizeType,
	Size
>::make_iterator(
	pos const _pos
) const
{
	return
		iterator(
			_pos,
			min_,
			sup_
		);
}

#endif

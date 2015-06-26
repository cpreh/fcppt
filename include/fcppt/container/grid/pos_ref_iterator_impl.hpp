//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/next_position.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_ref_iterator_decl.hpp>
#include <fcppt/container/grid/pos_reference_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_ref_iterator<
	Grid
>::pos_ref_iterator(
	iterator const &_iterator,
	dim const _size,
	pos const _current,
	min const _min,
	sup const _sup
)
:
	iterator_(
		_iterator
	),
	size_(
		_size
	),
	current_(
		_current
	),
	min_(
		_min
	),
	sup_(
		_sup
	)
{
}

template<
	typename Grid
>
void
fcppt::container::grid::pos_ref_iterator<
	Grid
>::increment()
{
	current_ =
		fcppt::container::grid::next_position(
			current_,
			min_,
			sup_
		);
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_ref_iterator<
	Grid
>::reference
fcppt::container::grid::pos_ref_iterator<
	Grid
>::dereference() const
{
	return
		reference(
			current_,
			*(
				iterator_
				+
				fcppt::cast::to_signed(
					current_.x()
					+
					current_.y()
					*
					size_.w()
				)
			)
		);
}

template<
	typename Grid
>
bool
fcppt::container::grid::pos_ref_iterator<
	Grid
>::equal(
	pos_ref_iterator const &_other
) const
{
	return
		current_
		==
		_other.current_;
}

#endif
